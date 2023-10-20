class Solution {
 public:
  long long maxPoints(vector<vector<int>>& points) {
    const int m = points.size();
    const int n = points[0].size();
    vector<vector<long long>> dp(2, vector<long long>(n));
    for (int j = 0; j < n; ++j) {
      dp[0][j] = points[0][j];
    }
    for (int i = 1; i < m; ++i) {
      long long prev_max = LLONG_MIN;
      for (int j = 0; j < n; ++j) {
        prev_max = max(prev_max, dp[1 - i % 2][j]);
        dp[i % 2][j] = prev_max;
        --prev_max;
      }
      prev_max = LLONG_MIN;
      for (int j = n - 1; j >= 0; --j) {
        prev_max = max(prev_max, dp[1 - i % 2][j]);
        dp[i % 2][j] = max(dp[i % 2][j], prev_max) + points[i][j];
        --prev_max;
      }
    }
    return *max_element(dp[1 - m % 2].begin(), dp[1 - m % 2].end());
  }
};
