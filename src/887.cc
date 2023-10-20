class Solution {
 public:
  int superEggDrop(int k, int n) {
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
      dp[i] = i;
    }
    vector<int> last_dp(n + 1);
    for (int kk = 2; kk <= k; ++kk) {
      swap(dp, last_dp);
      fill(dp.begin() + 1, dp.end(), INT_MAX);
      for (int i = 1, j = 1; i <= n; ++i) {
        while (j + 1 <= i && dp[j] < last_dp[i - j - 1]) {
          ++j;
        }
        dp[i] = 1 + last_dp[i - j];
        if (j + 1 <= i) {
          dp[i] = min(dp[i], 1 + dp[j]);
        }
      }
    }
    return dp[n];
  }
};
