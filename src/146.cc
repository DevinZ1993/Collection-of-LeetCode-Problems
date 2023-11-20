class LRUCache {
 public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    auto index_it = indices_.find(key);
    if (index_it == indices_.end()) {
      return -1;
    }
    auto kv_pair_it = index_it->second;
    const int value = kv_pair_it->second;
    kv_pairs_.emplace_back(key, value);
    index_it->second = prev(kv_pairs_.end());
    kv_pairs_.erase(kv_pair_it);
    return value;
  }

  void put(int key, int value) {
    const int old_value = get(key);
    if (old_value >= 0) {
      indices_.at(key)->second = value;
      return;
    }
    kv_pairs_.emplace_back(key, value);
    indices_.emplace(key, prev(kv_pairs_.end()));
    if (indices_.size() > capacity_) {
      indices_.erase(kv_pairs_.front().first);
      kv_pairs_.pop_front();
    }
  }

 private:
  const int capacity_;
  list<pair<int, int>> kv_pairs_;
  unordered_map<int, decltype(kv_pairs_)::iterator> indices_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
