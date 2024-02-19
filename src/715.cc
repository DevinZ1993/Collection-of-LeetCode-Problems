class RangeModule {
 public:
  RangeModule() {}

  void addRange(int left, int right) {
    // Find the first interval whose right point is not less than `left`.
    // If there's not one, create it.
    auto it = tree_.upper_bound(left);
    if (it == tree_.begin()) {
      it = tree_.emplace(left, right).first;
    } else {
      --it;
      if (it->second < left) {
        it = tree_.emplace(left, right).first;
      }
    }
    it->second = max(it->second, right);
    while (true) {
      const auto next_it = next(it);
      if (next_it == tree_.end() || next_it->first > right) {
        break;
      }
      it->second = max(it->second, next_it->second);
      tree_.erase(next_it);
    }
  }

  bool queryRange(int left, int right) {
    auto it = tree_.upper_bound(left);
    return it != tree_.begin() && prev(it)->second >= right;
  }

  void removeRange(int left, int right) {
    // Make `it` point at the first interval whose left point is not less than
    // `left`, while attending to the previous intersecting interval if any.
    auto it = tree_.lower_bound(left);
    if (it != tree_.begin()) {
      const auto prev_it = prev(it);
      if (prev_it->second > right) {
        tree_.emplace(right, prev_it->second);
      }
      prev_it->second = min(prev_it->second, left);
    }
    while (it != tree_.end() && it->first < right) {
      const auto next_it = next(it);
      if (it->second > right) {
        tree_.emplace(right, it->second);
        tree_.erase(it);
        break;
      }
      tree_.erase(it);
      it = next_it;
    }
  }

 private:
  map<int, int> tree_;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
