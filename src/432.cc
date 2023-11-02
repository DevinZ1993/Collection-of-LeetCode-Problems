class AllOne {
 public:
  struct Value {
    explicit Value(int count) : count(count) {}
    unordered_set<string> keys;
    const int count;
  };

  AllOne() {}

  void inc(string key) {
    auto it = indices_.find(key);
    if (it == indices_.end()) {
      if (values_.empty() || values_.front().count > 1) {
        values_.emplace_front(1);
      }
      values_.front().keys.insert(key);
      indices_.emplace(key, values_.begin());
      return;
    }
    auto value_it = it->second;
    value_it->keys.erase(key);
    auto next_value_it = next(value_it);
    if (next_value_it == values_.end() ||
        next_value_it->count > value_it->count + 1) {
      next_value_it = values_.emplace(next_value_it, value_it->count + 1);
    }
    next_value_it->keys.insert(key);
    it->second = next_value_it;
    if (value_it->keys.empty()) {
      values_.erase(value_it);
    }
  }

  void dec(string key) {
    auto it = indices_.find(key);
    if (it == indices_.end()) {
      return;
    }
    auto value_it = it->second;
    value_it->keys.erase(key);
    if (value_it->count > 1 && (value_it == values_.begin() ||
                                prev(value_it)->count < value_it->count - 1)) {
      values_.emplace(value_it, value_it->count - 1);
    }
    if (value_it->count == 1) {
      indices_.erase(it);
    } else {
      it->second = prev(value_it);
      it->second->keys.insert(key);
    }
    if (value_it->keys.empty()) {
      values_.erase(value_it);
    }
  }

  string getMaxKey() {
    if (values_.empty()) {
      return {};
    }
    return *values_.back().keys.begin();
  }

  string getMinKey() {
    if (values_.empty()) {
      return {};
    }
    return *values_.front().keys.begin();
  }

 private:
  list<Value> values_;
  unordered_map<string, list<Value>::iterator> indices_;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
