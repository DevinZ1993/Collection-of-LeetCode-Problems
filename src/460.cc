class LFUCache {
 public:
  struct Counter {
    explicit Counter(int value) : value(value) {}

    const int value;
    list<int> key_order;
  };

  struct State {
    int value = 0;
    list<Counter>::iterator counter_it;
    decltype(Counter::key_order)::iterator key_order_it;
  };

  LFUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    auto state_it = states_.find(key);
    if (state_it == states_.end()) {
      return -1;
    }

    auto &state = state_it->second;
    const auto counter_it = state.counter_it;
    auto next_counter_it = next(counter_it);
    if (next_counter_it == counters_.end() ||
        next_counter_it->value > counter_it->value + 1) {
      next_counter_it =
          counters_.emplace(next_counter_it, counter_it->value + 1);
    }
    next_counter_it->key_order.push_back(key);
    const auto key_order_it = state.key_order_it;
    state.key_order_it = prev(next_counter_it->key_order.end());
    counter_it->key_order.erase(key_order_it);
    if (counter_it->key_order.empty()) {
      counters_.erase(counter_it);
    }
    state.counter_it = next_counter_it;
    return state.value;
  }

  void put(int key, int value) {
    if (get(key) >= 0) {
      states_.at(key).value = value;
      return;
    }

    if (capacity_ == 0) {
      return;
    }

    if (states_.size() == capacity_) {
      states_.erase(counters_.front().key_order.front());
      counters_.front().key_order.pop_front();
      if (counters_.front().key_order.empty()) {
        counters_.pop_front();
      }
    }

    if (counters_.empty() || counters_.front().value > 1) {
      counters_.emplace_front(1);
    }
    counters_.front().key_order.push_back(key);
    states_.emplace(
        key, State{.value = value,
                   .counter_it = counters_.begin(),
                   .key_order_it = prev(counters_.front().key_order.end())});
  }

 private:
  const int capacity_;
  unordered_map<int, State> states_;
  list<Counter> counters_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
