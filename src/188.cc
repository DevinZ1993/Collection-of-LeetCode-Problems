class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    const int n = prices.size();
    if (n <= 2 * k) {
      vector<vector<int>> dp(n, vector<int>(2));
      dp[0][0] = 0;
      dp[0][1] = -prices[0];
      for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
      }
      return max(dp[n - 1][0], dp[n - 1][1]);
    }
    vector<vector<int>> dp(2, vector<int>(2 * k + 1, INT_MIN));
    dp[0][0] = dp[1][0] = 0;
    for (int i = 0; i < n; ++i) {
      const int index = i % 2;
      for (int j = 1; j < dp[index].size() && j <= i + 1; ++j) {
        dp[index][j] =
            max(dp[1 - index][j],
                dp[1 - index][j - 1] + (j % 2 == 0 ? prices[i] : -prices[i]));
      }
    }
    return *max_element(dp[1 - n % 2].begin(), dp[1 - n % 2].end());
  }
};
