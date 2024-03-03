struct TrieNode {
  array<unique_ptr<TrieNode>, 26> children;
  bool accept = false;
};

class Solution {
 public:
  bool differByOne(vector<string> &dict) {
    const int m = dict[0].size();
    TrieNode root;
    vector<tuple<TrieNode *, int, int>> stk;
    for (const string &str : dict) {
      stk.emplace_back(&root, 0, 0);
      while (!stk.empty()) {
        auto [node, index, state] = stk.back();
        stk.pop_back();
        if (node->accept) {
          return true;
        }
        if (state == 0) {
          for (int j = 0; j < node->children.size(); ++j) {
            if (node->children[j] == nullptr) {
              continue;
            }
            stk.emplace_back(node->children[j].get(), index + 1,
                             ('a' + j == str[index] ? 0 : 1));
          }
        } else if (node->children[str[index] - 'a'] != nullptr) {
          stk.emplace_back(node->children[str[index] - 'a'].get(), index + 1,
                           state);
        }
      }
      TrieNode *node = &root;
      for (char ch : str) {
        auto &child = node->children[ch - 'a'];
        if (child == nullptr) {
          child = make_unique<TrieNode>();
        }
        node = child.get();
      }
      node->accept = true;
    }
    return false;
  }
};
