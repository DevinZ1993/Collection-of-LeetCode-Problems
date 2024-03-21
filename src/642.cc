struct TrieNode {
  unique_ptr<TrieNode> &child(char c) {
    if (c == ' ') {
      return children.back();
    }
    return children[c - 'a'];
  }

  array<unique_ptr<TrieNode>, 27> children;
  string sentence;
  int time = 0;
};

class AutocompleteSystem {
 public:
  AutocompleteSystem(vector<string> &sentences, vector<int> &times)
      : current_node_(&root_) {
    for (int i = 0; i < sentences.size(); ++i) {
      TrieNode *node = &root_;
      for (char ch : sentences[i]) {
        auto &child = node->child(ch);
        if (child == nullptr) {
          child = make_unique<TrieNode>();
        }
        node = child.get();
      }
      node->sentence = sentences[i];
      node->time += times[i];
    }
  }

  vector<string> input(char c) {
    if (c == '#') {
      if (current_node_->sentence.empty()) {
        swap(current_node_->sentence, prefix_);
      }
      prefix_.clear();
      ++current_node_->time;
      current_node_ = &root_;
      return {};
    }
    prefix_.push_back(c);
    auto &child = current_node_->child(c);
    if (child == nullptr) {
      child = make_unique<TrieNode>();
    }
    current_node_ = child.get();

    const auto cmp = [](TrieNode *lhs, TrieNode *rhs) {
      if (lhs->time != rhs->time) {
        return lhs->time > rhs->time;
      }
      return lhs->sentence < rhs->sentence;
    };
    priority_queue<TrieNode *, vector<TrieNode *>, decltype(cmp)> q(cmp);
    vector<TrieNode *> stk{current_node_};
    while (!stk.empty()) {
      TrieNode *node = stk.back();
      stk.pop_back();
      if (node->time > 0) {
        q.push(node);
        if (q.size() > 3) {
          q.pop();
        }
      }
      for (auto &child : node->children) {
        if (child != nullptr) {
          stk.push_back(child.get());
        }
      }
    }
    vector<string> results;
    while (!q.empty()) {
      results.push_back(q.top()->sentence);
      q.pop();
    }
    reverse(results.begin(), results.end());
    return results;
  }

 private:
  TrieNode root_;
  TrieNode *current_node_;
  string prefix_;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
