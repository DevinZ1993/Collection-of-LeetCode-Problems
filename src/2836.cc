class Solution {
 public:
  long long getMaxFunctionValue(vector<int>& receiver, long long k) {
    const int n = receiver.size();
    const int h = static_cast<int>(log2(k)) + 1;
    vector<vector<pair<int, long long>>> dp(h, vector<pair<int, long long>>(n));
    for (int i = 0; i < n; ++i) {
      dp[0][i].first = receiver[i];
      dp[0][i].second = receiver[i];
    }
    for (int i = 1; i < h; ++i) {
      for (int j = 0; j < n; ++j) {
        const int next = dp[i - 1][j].first;
        dp[i][j].first = dp[i - 1][next].first;
        dp[i][j].second = dp[i - 1][j].second + dp[i - 1][next].second;
      }
    }
    long long result = 0;
    for (int i = 0; i < n; ++i) {
      long long local = i;
      int index = i;
      for (int offset = 0; offset < h; ++offset) {
        if ((k & (1LL << offset)) != 0) {
          local += dp[offset][index].second;
          index = dp[offset][index].first;
        }
      }
      result = max(result, local);
    }
    return result;
  }
};
