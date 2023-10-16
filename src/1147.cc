class Solution {
 public:
  int longestDecomposition(string text) {
    const int n = text.size();
    vector<vector<bool>> dp(n / 2, vector<bool>(n / 2));
    for (int len = 1; len <= n / 2; ++len) {
      for (int i = 0; i + len <= n / 2; ++i) {
        dp[len - 1][i] = (text[i] == text[n - i - len] &&
                          text[i + len - 1] == text[n - i - 1]);
        if (len >= 3) {
          dp[len - 1][i] = (dp[len - 1][i] && dp[len - 3][i + 1]);
        }
      }
    }
    vector<int> dp2(n / 2 + 1, 1);
    if (n % 2 == 0) {
      dp2[n / 2] = 0;
    }
    for (int i = n / 2 - 1; i >= 0; --i) {
      for (int j = i + 1; j < dp2.size(); ++j) {
        if (dp[j - i - 1][i]) {
          dp2[i] = max(dp2[i], 2 + dp2[j]);
        }
      }
    }
    return dp2[0];
  }
};
