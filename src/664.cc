class Solution {
 public:
  int strangePrinter(string s) {
    const int n = s.size();
    vector<vector<int>> dp(n);
    dp[0].resize(n, 1);
    for (int len = 2; len <= n; ++len) {
      dp[len - 1].resize(n - len + 1);
      for (int i = 0; i + len <= n; ++i) {
        dp[len - 1][i] = dp[len - 2][i + 1] + 1;
        for (int j = i + 1; j < i + len; ++j) {
          if (s[j] == s[i]) {
            dp[len - 1][i] =
                min(dp[len - 1][i],
                    dp[j - i - 1][i] +
                        (j == i + len - 1 ? 0 : dp[i + len - 2 - j][j + 1]));
          }
        }
      }
    }
    return dp[n - 1][0];
  }
};
