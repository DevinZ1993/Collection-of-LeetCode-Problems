class Solution {
 public:
  int distinctEchoSubstrings(string text) {
    constexpr long long base = 26LL;
    constexpr long long mod = 1'000'000'007LL;
    int result = 0;
    unordered_map<long long, vector<int>> vis;
    const int n = text.size();
    long long pow = 1LL;
    for (int len = 1; len * 2 <= n; ++len) {
      pow = pow * base % mod;
      vis.clear();
      int cnt = 0;
      long long val = 0;
      for (int i = 0; i < n; ++i) {
        val = (val * base % mod + (text[i] - 'a')) % mod;
        if (i >= len) {
          val = (val + mod - pow * (text[i - len] - 'a') % mod) % mod;
        }
        if (i >= len && text[i] == text[i - len]) {
          ++cnt;
        }
        if (i >= len * 2 && text[i - len] == text[i - 2 * len]) {
          --cnt;
        }
        if (cnt != len) {
          continue;
        }
        auto it = vis.emplace(val, vector<int>{}).first;
        bool found = false;
        for (const int index : it->second) {
          if (equal(text.begin() + i - len + 1, text.begin() + i + 1,
                    text.begin() + index)) {
            found = true;
            break;
          }
        }
        if (!found) {
          it->second.push_back(i - len + 1);
          ++result;
        }
      }
    }
    return result;
  }
};
