class Skiplist {
 public:
  Skiplist() {
    srand(time(nullptr));
    heads_.push_back(make_unique<Node>());
  }

  bool search(int target) {
    auto [_, prev] = doSearch(target);
    return prev->next != nullptr && prev->next->value == target;
  }

  void add(int num) {
    vector<Node *> prevs(heads_.size());
    Node *prev = heads_.back().get();
    for (int level = heads_.size() - 1; level >= 0; --level) {
      while (prev->next != nullptr && prev->next->value < num) {
        prev = prev->next.get();
      }
      prevs[level] = prev;
      prev = prev->down;
    }
    for (int level = 0;; ++level) {
      auto new_node = make_unique<Node>(num);
      new_node->next = move(prevs[level]->next);
      if (level > 0) {
        new_node->down = prevs[level - 1]->next.get();
        new_node->down->up = new_node.get();
      }
      prevs[level]->next = move(new_node);
      if (rand() % 5 > 0) {
        break;
      }
      if (heads_.size() == level + 1) {
        auto new_head = make_unique<Node>();
        new_head->down = heads_.back().get();
        heads_.back()->up = new_head.get();
        prevs.push_back(new_head.get());
        heads_.push_back(move(new_head));
      }
    }
  }

  bool erase(int num) {
    auto [level, prev] = doSearch(num);
    if (prev->next == nullptr || prev->next->value != num) {
      return false;
    }
    for (; level >= 0; --level) {
      while (prev->next->value < num) {
        prev = prev->next.get();
        assert(prev->next != nullptr);
      }
      prev->next = move(prev->next->next);
      prev = prev->down;
      if (level > 0 && heads_[level]->next == nullptr) {
        assert(heads_.size() == level + 1);
        heads_.pop_back();
      }
    }
    return true;
  }

 private:
  struct Node {
    explicit Node(int value = 0) : value(value) {}

    const int value;
    Node *prev = nullptr;
    unique_ptr<Node> next;
    Node *up = nullptr;
    Node *down = nullptr;
  };

  pair<int, Node *> doSearch(int target) {
    assert(!heads_.empty());
    Node *prev = heads_.back().get();
    for (int level = heads_.size() - 1; level >= 0; --level) {
      assert(prev != nullptr);
      while (prev->next != nullptr && prev->next->value < target) {
        prev = prev->next.get();
      }
      if (level == 0 ||
          (prev->next != nullptr && prev->next->value == target)) {
        return {level, prev};
      }
      prev = prev->down;
    }
    return {0, nullptr};
  }

  vector<unique_ptr<Node>> heads_;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
