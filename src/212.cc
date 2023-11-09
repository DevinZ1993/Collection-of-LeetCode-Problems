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
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    TrieNode root;
    for (const string &word : words) {
      root.insert(word);
    }
    const int m = board.size();
    const int n = board[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vector<tuple<int, int, TrieNode *>> stk;
    vector<string> results;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        solve(board, i, j, vis, stk, &root, results);
      }
    }
    return results;
  }

 private:
  static constexpr array<pair<int, int>, 4> kDirs = {
      {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}};

  void solve(const vector<vector<char>> &board, int start_i, int start_j,
             vector<vector<bool>> &vis,
             vector<tuple<int, int, TrieNode *>> &stk, TrieNode *root,
             vector<string> &results) {
    if (root->children[board[start_i][start_j] - 'a'] == nullptr) {
      return;
    }

    string word;
    stk.emplace_back(start_i, start_j,
                     root->children[board[start_i][start_j] - 'a'].get());
    while (!stk.empty()) {
      auto [i, j, node] = stk.back();
      stk.pop_back();
      if (node == nullptr) {
        word.pop_back();
        vis[i][j] = false;
        continue;
      }
      stk.emplace_back(i, j, nullptr);
      word.push_back(board[i][j]);
      vis[i][j] = true;
      if (node->accept) {
        node->accept = false;
        results.push_back(word);
      }
      for (const auto [di, dj] : kDirs) {
        const int next_i = i + di;
        const int next_j = j + dj;
        if (next_i < 0 || next_i >= board.size() || next_j < 0 ||
            next_j >= board[next_i].size() || vis[next_i][next_j] ||
            node->children[board[next_i][next_j] - 'a'] == nullptr) {
          continue;
        }
        stk.emplace_back(next_i, next_j,
                         node->children[board[next_i][next_j] - 'a'].get());
      }
    }
  }
};
