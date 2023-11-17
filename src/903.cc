class Solution {
 public:
  int numPermsDISequence(string s) {
    constexpr long long mod = 1'000'000'007LL;
    const int n = s.size();
    vector<vector<long long>> dp(2, vector<long long>(n + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      const int index = 1 - i % 2;
      if (s[i] == 'I') {
        dp[index][0] = 0;
        long long sum = 0;
        for (int j = 1; j <= i + 1; ++j) {
          sum = (sum + dp[1 - index][j - 1]) % mod;
          dp[index][j] = sum;
        }
      } else {
        dp[index][i + 1] = 0;
        long long sum = 0;
        for (int j = i; j >= 0; --j) {
          sum = (sum + dp[1 - index][j]) % mod;
          dp[index][j] = sum;
        }
      }
    }
    long long result = 0;
    for (int i = 0; i <= n; ++i) {
      result = (result + dp[n % 2][i]) % mod;
    }
    return result;
  }
};
