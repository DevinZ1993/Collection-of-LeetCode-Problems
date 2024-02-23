struct TrieNode {
  void Insert(const string &word) {
    TrieNode *node = this;
    for (int i = 0, j = word.size() - 1; i < word.size(); ++i, --j) {
      const int key = 128 * (word[i] - 'a') + (word[j] - 'a');
      auto &child = node->children[key];
      if (child == nullptr) {
        child = make_unique<TrieNode>();
      }
      node = child.get();
      ++node->cnt;
    }
  }

  int cnt = 0;
  unordered_map<int, unique_ptr<TrieNode>> children;
};

class Solution {
 public:
  long long countPrefixSuffixPairs(vector<string> &words) {
    long long result = 0;
    TrieNode root;
    for (auto it = words.rbegin(); it != words.rend(); ++it) {
      const string &word = *it;
      TrieNode *node = &root;
      for (int i = 0, j = word.size() - 1; i < word.size(); ++i, --j) {
        auto node_it =
            node->children.find(128 * (word[i] - 'a') + (word[j] - 'a'));
        if (node_it == node->children.end()) {
          node = nullptr;
          break;
        }
        node = node_it->second.get();
      }
      if (node != nullptr) {
        result += node->cnt;
      }
      root.Insert(*it);
    }
    return result;
  }
};
