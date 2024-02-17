class H2O {
 public:
  H2O() {}

  void hydrogen(function<void()> releaseHydrogen) {
    unique_lock guard(mu);
    while (grouped || h_ready == 2) {
      cv.wait(guard, [this]() { return !grouped && h_ready < 2; });
    }
    ++h_ready;
    cv.notify_all();
    while (!grouped) {
      cv.wait(guard, [this]() { return grouped; });
    }
    guard.unlock();

    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();

    guard.lock();
    --h_ready;
    cv.notify_all();
  }

  void oxygen(function<void()> releaseOxygen) {
    unique_lock guard(mu);
    while (grouped || o_ready == 1) {
      cv.wait(guard, [this]() { return !grouped && o_ready < 1; });
    }
    ++o_ready;
    while (h_ready < 2) {
      cv.wait(guard, [this]() { return h_ready == 2; });
    }
    grouped = true;
    cv.notify_all();
    guard.unlock();

    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();

    guard.lock();
    while (h_ready > 0) {
      cv.wait(guard, [this]() { return h_ready == 0; });
    }
    --o_ready;
    grouped = false;
    cv.notify_all();
  }

 private:
  int h_ready = 0;
  int o_ready = 0;
  bool grouped = false;
  mutex mu;
  condition_variable cv;
};
