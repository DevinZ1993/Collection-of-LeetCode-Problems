class Solution {
 public:
  bool isMatch(string s, string p) {
    const int m = p.size();
    const int n = s.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
    dp[0][0] = true;
    for (int i = 1; i < m && p[i] == '*'; i += 2) {
      dp[i + 1][0] = true;
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (p[i] == '*') {
          assert(i > 0);
          dp[i + 1][j + 1] =
              dp[i - 1][j + 1] ||
              ((p[i - 1] == '.' || p[i - 1] == s[j]) && dp[i + 1][j]);
        } else {
          dp[i + 1][j + 1] = ((p[i] == '.' || p[i] == s[j]) && dp[i][j]);
        }
      }
    }
    return dp[m][n];
  }
};
