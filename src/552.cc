class Solution {
 public:
  int checkRecord(int n) {
    constexpr long long mod = 1'000'000'007LL;
    vector<vector<vector<long long>>> dp(
        2, vector<vector<long long>>(2, vector<long long>(3)));
    dp[0][0][0] = 1;
    for (int len = 1; len <= n; ++len) {
      const int index = len % 2;
      for (int i = 0; i < dp[index].size(); ++i) {
        fill(dp[index][i].begin(), dp[index][i].end(), 0);
      }
      for (int i = 0; i < dp[1 - index].size(); ++i) {
        for (int j = 0; j < dp[1 - index][i].size(); ++j) {
          dp[index][i][0] = (dp[index][i][0] + dp[1 - index][i][j]) % mod;
          if (i == 0) {
            dp[index][1][0] = (dp[index][1][0] + dp[1 - index][0][j]) % mod;
          }
          if (j + 1 < dp[index][i].size()) {
            dp[index][i][j + 1] =
                (dp[index][i][j + 1] + dp[1 - index][i][j]) % mod;
          }
        }
      }
    }
    long long result = 0;
    for (int i = 0; i < dp[n % 2].size(); ++i) {
      for (int j = 0; j < dp[n % 2][i].size(); ++j) {
        result = (result + dp[n % 2][i][j]) % mod;
      }
    }
    return result;
  }
};
