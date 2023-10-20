class Solution {
 public:
  int minCostII(vector<vector<int>>& costs) {
    const int m = costs.size();
    const int n = costs[0].size();
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0] = costs[0];
    for (int i = 1; i < m; ++i) {
      int min_val = INT_MAX;
      int min_cnt = 0;
      int second_val = INT_MAX;
      for (int j = 0; j < n; ++j) {
        if (dp[1 - i % 2][j] < min_val) {
          second_val = min_val;
          min_val = dp[1 - i % 2][j];
          min_cnt = 1;
        } else if (dp[1 - i % 2][j] == min_val) {
          ++min_cnt;
        } else if (dp[1 - i % 2][j] < second_val) {
          second_val = dp[1 - i % 2][j];
        }
      }
      for (int j = 0; j < n; ++j) {
        if (dp[1 - i % 2][j] > min_val || min_cnt > 1) {
          dp[i % 2][j] = min_val + costs[i][j];
        } else {
          dp[i % 2][j] = second_val + costs[i][j];
        }
      }
    }
    return *min_element(dp[1 - m % 2].begin(), dp[1 - m % 2].end());
  }
};
