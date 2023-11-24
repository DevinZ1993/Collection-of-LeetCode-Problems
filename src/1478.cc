class Solution {
 public:
  int minDistance(vector<int>& houses, int k) {
    sort(houses.begin(), houses.end());
    const int n = houses.size();
    vector<int> sums(n + 1);
    for (int i = 0; i < n; ++i) {
      sums[i + 1] = sums[i] + houses[i];
    }
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
      dp[i] = sums[i] - sums[i - i / 2] - sums[i / 2];
    }
    for (int kk = 2; kk <= k; ++kk) {
      for (int i = n; i >= kk; --i) {
        dp[i] = INT_MAX;
        for (int j = i - 1; j >= kk - 1; --j) {
          const int len = i - j;
          dp[i] = min(dp[i], dp[j] + sums[i] - sums[i - len / 2] -
                                 sums[j + len / 2] + sums[j]);
        }
      }
    }
    return dp[n];
  }
};
