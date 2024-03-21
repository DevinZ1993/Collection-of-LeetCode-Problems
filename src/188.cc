class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    vector<int> dp(2 * k + 1, INT_MIN);
    dp[0] = 0;
    for (int price : prices) {
      for (int i = dp.size() - 2; i >= 0; --i) {
        if (dp[i] == INT_MIN) {
          continue;
        }
        const int new_val = (i % 2 == 0) ? dp[i] - price : dp[i] + price;
        dp[i + 1] = max(dp[i + 1], new_val);
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};
