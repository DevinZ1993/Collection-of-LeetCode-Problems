class MKAverage {
 public:
  MKAverage(int m, int k) : m_(m), k_(k) {}

  void addElement(int num) {
    if (q_.size() == m_) {
      const int head = q_.front();
      q_.pop_front();
      if (small_.try_remove(head)) {
        small_.insert(middle_.pop_min());
      } else if (large_.try_remove(head)) {
        large_.insert(middle_.pop_max());
      } else {
        assert(middle_.try_remove(head));
      }
    }
    q_.push_back(num);
    if (small_.size == 0 || num <= *small_.data.rbegin()) {
      small_.insert(num);
      if (small_.size <= k_) {
        return;
      }
      num = small_.pop_max();
    }
    if (large_.size == 0 || num >= *large_.data.begin()) {
      large_.insert(num);
      if (large_.size <= k_) {
        return;
      }
      num = large_.pop_min();
    }
    middle_.insert(num);
    if (small_.size < k_) {
      small_.insert(middle_.pop_min());
    } else if (large_.size < k_) {
      large_.insert(middle_.pop_max());
    }
  }

  int calculateMKAverage() {
    if (q_.size() < m_) {
      return -1;
    }
    return middle_.sum / middle_.size;
  }

 private:
  struct Tree {
    void insert(int x) {
      sum += x;
      ++size;
      data.insert(x);
    }

    bool try_remove(int x) {
      auto it = data.find(x);
      if (it == data.end()) {
        return false;
      }
      data.erase(it);
      --size;
      sum -= x;
      return true;
    }

    int pop_min() {
      const int value = *data.begin();
      assert(try_remove(value));
      return value;
    }

    int pop_max() {
      const int value = *data.rbegin();
      assert(try_remove(value));
      return value;
    }

    long long sum = 0;
    int size = 0;
    multiset<int> data;
  };

  Tree small_;
  Tree middle_;
  Tree large_;
  deque<int> q_;

  const int m_;
  const int k_;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
