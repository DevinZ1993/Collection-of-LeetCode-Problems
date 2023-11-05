class RandomizedCollection {
public:
  RandomizedCollection() { srand(time(nullptr)); }

  bool insert(int val) {
    vals_.push_back(val);
    auto it = indices_.find(val);
    if (it == indices_.end()) {
      indices_[val].insert(vals_.size() - 1);
      return true;
    }
    it->second.insert(vals_.size() - 1);
    return false;
  }

  bool remove(int val) {
    auto it = indices_.find(val);
    if (it == indices_.end()) {
      return false;
    }
    auto index_it = it->second.begin();
    const int index = *index_it;
    it->second.erase(index_it);
    if (it->second.empty()) {
      indices_.erase(it);
    }
    if (index + 1 == vals_.size()) {
      vals_.pop_back();
    } else {
      auto &tail_indices = indices_.at(vals_.back());
      tail_indices.erase(vals_.size() - 1);
      tail_indices.insert(index);
      swap(vals_[index], vals_.back());
      vals_.pop_back();
    }
    return true;
  }

  int getRandom() { return vals_[random() % vals_.size()]; }

private:
  vector<int> vals_;
  unordered_map<int, unordered_set<int>> indices_;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
