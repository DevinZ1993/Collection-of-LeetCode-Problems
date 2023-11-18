class Solution {
 public:
  int mergeStones(vector<int>& stones, int k) {
    const int n = stones.size();
    if ((n - 1) % (k - 1) != 0) {
      return -1;
    }

    vector<int> sums(n + 1);
    for (int i = 0; i < n; ++i) {
      sums[i + 1] = sums[i] + stones[i];
    }

    vector<vector<int>> dp(n);
    dp[0].resize(n);
    for (int len = 2; len <= n; ++len) {
      dp[len - 1].resize(n - len + 1, INT_MAX);
      for (int i = 0; i + len <= n; ++i) {
        const int merge_cost =
            (len - 1) % (k - 1) == 0 ? sums[i + len] - sums[i] : 0;
        for (int j = i + 1; j < i + len; j += (k - 1)) {
          dp[len - 1][i] =
              min(dp[len - 1][i],
                  dp[j - i - 1][i] + dp[i + len - j - 1][j] + merge_cost);
        }
      }
    }
    return dp[n - 1][0];
  }
};
