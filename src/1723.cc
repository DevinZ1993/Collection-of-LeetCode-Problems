class Solution {
 public:
  int minimumTimeRequired(vector<int>& jobs, int k) {
    const int n = jobs.size();
    vector<vector<int>> dp(k, vector<int>(1 << n, INT_MAX));
    dp[0][0] = 0;
    for (int state = 1; state < dp[0].size(); ++state) {
      for (int i = 0; i < n; ++i) {
        if (state & (1 << i)) {
          dp[0][state] = dp[0][state & ~(1 << i)] + jobs[i];
          break;
        }
      }
    }
    for (int i = 1; i < dp.size(); ++i) {
      for (int state = 0; state < dp[i - 1].size(); ++state) {
        const int rest = (((1 << n) - 1) & ~state);
        for (int sub = rest; sub > 0; sub = rest & (sub - 1)) {
          dp[i][state | sub] =
              min(dp[i][state | sub], max(dp[i - 1][state], dp[0][sub]));
        }
      }
    }
    return dp.back().back();
  }
};
