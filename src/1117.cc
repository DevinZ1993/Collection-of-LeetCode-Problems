class H2O {
 public:
  H2O() {}

  void hydrogen(function<void()> releaseHydrogen) {
    {
      unique_lock ul(mu_);
      while (h_waiting_ == 2) {
        waiting_cv_.wait(ul, [this]() { return h_waiting_ < 2; });
      }
      ++h_waiting_;
      teamup_cv_.notify_all();
      while (h_waiting_ < 2 || o_waiting_ < 1) {
        teamup_cv_.wait(
            ul, [this]() { return h_waiting_ == 2 && o_waiting_ == 1; });
      }
    }
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();
    {
      unique_lock ul(mu_);
      ++complete_;
      complete_cv_.notify_one();
    }
  }

  void oxygen(function<void()> releaseOxygen) {
    {
      unique_lock ul(mu_);
      while (o_waiting_ == 1) {
        waiting_cv_.wait(ul, [this]() { return o_waiting_ < 1; });
      }
      ++o_waiting_;
      teamup_cv_.notify_all();
      while (h_waiting_ < 2 || o_waiting_ < 1) {
        teamup_cv_.wait(
            ul, [this]() { return h_waiting_ == 2 && o_waiting_ == 1; });
      }
    }
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();
    {
      unique_lock ul(mu_);
      ++complete_;
      while (complete_ < 3) {
        complete_cv_.wait(ul, [this]() { return complete_ == 3; });
      }
      h_waiting_ = 0;
      o_waiting_ = 0;
      complete_ = 0;
      waiting_cv_.notify_all();
    }
  }

 private:
  mutex mu_;
  condition_variable waiting_cv_;
  int h_waiting_ = 0;
  int o_waiting_ = 0;
  condition_variable teamup_cv_;
  int team_ = 0;
  condition_variable complete_cv_;
  int complete_ = 0;
};
