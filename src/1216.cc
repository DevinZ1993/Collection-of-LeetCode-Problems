class Solution {
 public:
  bool isValidPalindrome(string s, int k) {
    const int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        if (s[i] == s[n - j - 1]) {
          dp[i + 1][j + 1] = max(dp[i + 1][j + 1], 1 + dp[i][j]);
        }
      }
    }
    return dp[n][n] >= n - k;
  }
};
