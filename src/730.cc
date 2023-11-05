class Solution {
 public:
  int countPalindromicSubsequences(string s) {
    constexpr int mod = 1'000'000'007;
    const int n = s.size();
    vector<vector<array<int, 4>>> dp(n, vector<array<int, 4>>(n));
    for (int i = 0; i < n; ++i) {
      dp[0][i][s[i] - 'a'] = 1;
    }
    if (n >= 2) {
      for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == s[i + 1]) {
          dp[1][i][s[i] - 'a'] = 2;
        } else {
          dp[1][i][s[i] - 'a'] = 1;
          dp[1][i][s[i + 1] - 'a'] = 1;
        }
      }
    }
    for (int len = 3; len <= n; ++len) {
      for (int i = 0; i + len <= n; ++i) {
        for (int j = 0; j < 4; ++j) {
          if (s[i] == 'a' + j && s[i + len - 1] == 'a' + j) {
            dp[len - 1][i][j] = 2;
            for (int prev : dp[len - 3][i + 1]) {
              dp[len - 1][i][j] = (dp[len - 1][i][j] + prev) % mod;
            }
          } else if (s[i] == 'a' + j) {
            dp[len - 1][i][j] = dp[len - 2][i][j];
          } else {
            dp[len - 1][i][j] = dp[len - 2][i + 1][j];
          }
        }
      }
    }
    int result = 0;
    for (int cnt : dp[n - 1][0]) {
      result = (result + cnt) % mod;
    }
    return result;
  }
};
