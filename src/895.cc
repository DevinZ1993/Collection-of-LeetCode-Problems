class FreqStack {
 public:
  FreqStack() {}

  void push(int val) {
    const int index = cnts_[val]++;
    if (values_.size() == index) {
      values_.emplace_back();
    }
    values_[index].push_back(val);
  }

  int pop() {
    const int value = values_.back().back();
    values_.back().pop_back();
    if (values_.back().empty()) {
      values_.pop_back();
    }
    auto it = cnts_.find(value);
    assert(it != cnts_.end());
    if (--it->second == 0) {
      cnts_.erase(it);
    }
    return value;
  }

 private:
  unordered_map<int, int> cnts_;
  vector<vector<int>> values_;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
