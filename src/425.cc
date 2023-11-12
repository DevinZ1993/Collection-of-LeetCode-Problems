struct TrieNode {
  void insert(const string &s) {
    TrieNode *node = this;
    for (char ch : s) {
      auto &child = node->children[ch - 'a'];
      if (child == nullptr) {
        child = make_unique<TrieNode>();
      }
      node = child.get();
    }
    node->accept = true;
  }

  array<unique_ptr<TrieNode>, 26> children;
  bool accept = false;
};

class Solution {
 public:
  vector<vector<string>> wordSquares(vector<string> &words) {
    TrieNode root;
    for (const string &word : words) {
      root.insert(word);
    }
    vector<vector<string>> results;
    vector<string> result;
    result.reserve(words[0].size());
    solve(results, result, root, words[0].size());
    return results;
  }

 private:
  void solve(vector<vector<string>> &results, vector<string> &result,
             TrieNode &root, int n) {
    const int index = result.size();
    if (index == n) {
      results.push_back(result);
      return;
    }
    TrieNode *node = &root;
    string row;
    row.reserve(n);
    for (int i = 0; i < index; ++i) {
      const char ch = result[i][index];
      if (node->children[ch - 'a'] == nullptr) {
        return;
      }
      node = node->children[ch - 'a'].get();
      row.push_back(ch);
    }
    // Non-recursive backtracking within a recursive backtracking.
    vector<tuple<TrieNode *, char, int>> stk;
    stk.emplace_back(node, '\0', 0);
    while (!stk.empty()) {
      auto [node, ch, state] = stk.back();
      stk.pop_back();
      if (state == 2) {
        assert(ch == row.back());
        row.pop_back();
        continue;
      }
      if (state == 1) {
        assert(ch >= 'a' && ch <= 'z');
        row.push_back(ch);
        stk.emplace_back(node, ch, 2);
        stk.emplace_back(node->children[ch - 'a'].get(), '\0', 0);
        continue;
      }
      if (node->accept) {
        assert(row.size() == n);
        result.push_back(row);
        solve(results, result, root, n);
        result.pop_back();
        continue;
      }
      for (char next_ch = 'a'; next_ch <= 'z'; ++next_ch) {
        if (node->children[next_ch - 'a'] != nullptr) {
          stk.emplace_back(node, next_ch, 1);
        }
      }
    }
  }
};
