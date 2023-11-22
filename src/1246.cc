class Solution {
 public:
  int minimumMoves(vector<int>& arr) {
    const int n = arr.size();
    vector<vector<int>> dp(n);
    dp[0].resize(n, 1);
    for (int len = 2; len <= n; ++len) {
      dp[len - 1].resize(n - len + 1, len);
      for (int i = 0; i + len <= n; ++i) {
        dp[len - 1][i] = 1 + dp[len - 2][i + 1];
        for (int j = i + 1; j < i + len; ++j) {
          if (arr[i] == arr[j]) {
            dp[len - 1][i] =
                min(dp[len - 1][i],
                    (j == i + 1 ? 1 : dp[j - i - 2][i + 1]) +
                        (j + 1 == i + len ? 0 : dp[i + len - j - 2][j + 1]));
          }
        }
      }
    }
    return dp[n - 1][0];
  }
};
