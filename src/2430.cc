class Solution {
 public:
  int deleteString(string s) {
    const int n = s.size();
    vector<vector<bool>> prefixes(n, vector<bool>(n));
    for (int len = 1; len * 2 <= n; ++len) {
      int matches = 0;
      for (int i = 0; i + len <= n; ++i) {
        if (i >= len && s[i - len] == s[i]) {
          --matches;
        }
        if (s[i] == s[i + len]) {
          ++matches;
        }
        if (i >= len - 1) {
          prefixes[len - 1][i - len + 1] = (matches == len);
        }
      }
    }
    vector<int> dp(n, 1);
    for (int i = n - 1; i >= 0; --i) {
      for (int len = 1; i + 2 * len <= n; ++len) {
        if (prefixes[len - 1][i]) {
          dp[i] = max(dp[i], dp[i + len] + 1);
        }
      }
    }
    return dp[0];
  }
};
