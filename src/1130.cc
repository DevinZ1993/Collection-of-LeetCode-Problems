class Solution {
 public:
  int mctFromLeafValues(vector<int>& arr) {
    const int n = arr.size();
    vector<vector<pair<int, int>>> dp(n);
    dp[0].reserve(n);
    for (int i = 0; i < n; ++i) {
      dp[0].emplace_back(arr[i], 0);
    }
    for (int len = 2; len <= n; ++len) {
      dp[len - 1].resize(n - len + 1);
      for (int i = 0; i + len <= n; ++i) {
        dp[len - 1][i].first = max(arr[i], dp[len - 2][i + 1].first);
        dp[len - 1][i].second = INT_MAX;
        for (int j = i + 1; j < i + len; ++j) {
          dp[len - 1][i].second =
              min(dp[len - 1][i].second,
                  dp[j - i - 1][i].first * dp[i + len - 1 - j][j].first +
                      dp[j - i - 1][i].second + dp[i + len - 1 - j][j].second);
        }
      }
    }
    return dp[n - 1][0].second;
  }
};
