class Solution {
 public:
  int superEggDrop(int k, int n) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    for (int nn = 1; nn <= n; ++nn) {
      dp[1][nn] = nn;
    }
    for (int kk = 2; kk <= k; ++kk) {
      for (int nn = 1, m = 1; nn <= n; ++nn) {
        for (; m <= nn; ++m) {
          if (dp[kk - 1][m - 1] >= dp[kk][nn - m]) {
            break;
          }
        }
        dp[kk][nn] = INT_MAX;
        if (m <= nn) {
          dp[kk][nn] = 1 + dp[kk - 1][m - 1];
        }
        if (m > 1) {
          dp[kk][nn] = min(dp[kk][nn], 1 + dp[kk][nn - m + 1]);
        }
      }
    }
    return dp[k][n];
  }
};
