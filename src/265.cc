class Solution {
 public:
  int minCostII(vector<vector<int>>& costs) {
    const int m = costs.size();
    const int n = costs[0].size();
    vector<int> dp(costs[0]);
    for (int i = 1; i < m; ++i) {
      int min_val = INT_MAX;
      int min_count = 0;
      int second_min = INT_MAX;
      for (int j = 0; j < n; ++j) {
        if (dp[j] < min_val) {
          second_min = min_val;
          min_val = dp[j];
          min_count = 1;
        } else if (dp[j] == min_val) {
          ++min_count;
        } else if (dp[j] < second_min) {
          second_min = dp[j];
        }
      }
      for (int j = 0; j < n; ++j) {
        dp[j] = costs[i][j] +
                ((dp[j] != min_val || min_count > 1) ? min_val : second_min);
      }
    }
    return *min_element(dp.begin(), dp.end());
  }
};
