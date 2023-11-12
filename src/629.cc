class Solution {
 public:
  int kInversePairs(int n, int k) {
    constexpr int mod = 1'000'000'007;
    vector<vector<int>> dp(2, vector<int>(k + 1));
    dp[1][0] = 1;
    for (int i = 2; i <= n; ++i) {
      const int index = i % 2;
      for (int j = 1; j < dp[1 - index].size(); ++j) {
        dp[1 - index][j] = (dp[1 - index][j] + dp[1 - index][j - 1]) % mod;
      }
      dp[index][0] = 1;
      for (int j = 1; j <= k; ++j) {
        if (j > i * (i - 1) / 2) {
          dp[index][j] = 0;
          continue;
        }
        const int min_j = max(0, j - i + 1);
        const int max_j = min(j, (i - 1) * (i - 2) / 2);
        dp[index][j] = (dp[1 - index][max_j] + mod -
                        (min_j == 0 ? 0 : dp[1 - index][min_j - 1])) %
                       mod;
      }
    }
    return dp[n % 2][k];
  }
};
