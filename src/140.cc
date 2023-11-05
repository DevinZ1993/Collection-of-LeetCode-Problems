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

  bool search(const string &s) const {
    const TrieNode *node = this;
    for (char ch : s) {
      const auto &child = node->children[ch - 'a'];
      if (child == nullptr) {
        return false;
      }
      node = child.get();
    }
    return node->accept;
  }

  array<unique_ptr<TrieNode>, 26> children;
  bool accept = false;
};

class Solution {
public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    TrieNode root;
    for (const string &word : wordDict) {
      root.insert(word);
    }

    const int n = s.size();
    vector<vector<int>> dp(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      string word;
      word.reserve(n - i);
      for (int j = i; j < n; ++j) {
        word.push_back(s[j]);
        if (!root.search(word) || (j + 1 < n && dp[j + 1].empty())) {
          continue;
        }
        dp[i].push_back(j + 1);
      }
    }

    vector<string> results;
    string result;
    vector<pair<int, int>> stk;
    stk.emplace_back(0, 0);
    while (!stk.empty()) {
      auto [index, length] = stk.back();
      stk.pop_back();
      if (index == n) {
        assert(length == 0);
        results.emplace_back(result);
        continue;
      }
      if (length < 0) {
        result.resize(result.size() + length);
        continue;
      }
      if (length == 0) {
        for (int next : dp[index]) {
          stk.emplace_back(index, next - index);
        }
        continue;
      }

      const int next = index + length;
      result.append(s.substr(index, length));
      if (next < n) {
        result.push_back(' ');
        stk.emplace_back(index, -length - 1);
      } else {
        stk.emplace_back(index, -length);
      }
      stk.emplace_back(index + length, 0);
    }
    return results;
  }
};
