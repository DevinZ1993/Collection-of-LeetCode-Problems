class Solution {
 public:
  int numDecodings(string s) {
    constexpr long long mod = 1'000'000'007LL;
    const int n = s.size();
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '*') {
        dp[i + 1] = 9 * dp[i] % mod;
      } else if (s[i] != '0') {
        dp[i + 1] = dp[i];
      }
      if (i > 0) {
        if (s[i - 1] == '1') {
          if (s[i] == '*') {
            dp[i + 1] = (dp[i + 1] + dp[i - 1] * 9 % mod) % mod;
          } else {
            dp[i + 1] = (dp[i + 1] + dp[i - 1]) % mod;
          }
        } else if (s[i - 1] == '2') {
          if (s[i] == '*') {
            dp[i + 1] = (dp[i + 1] + dp[i - 1] * 6 % mod) % mod;
          } else if (s[i] >= '0' && s[i] <= '6') {
            dp[i + 1] = (dp[i + 1] + dp[i - 1]) % mod;
          }
        } else if (s[i - 1] == '*') {
          if (s[i] >= '0' && s[i] <= '6') {
            dp[i + 1] = (dp[i + 1] + dp[i - 1] * 2 % mod) % mod;
          } else if (s[i] >= '7' && s[i] <= '9') {
            dp[i + 1] = (dp[i + 1] + dp[i - 1]) % mod;
          } else {
            dp[i + 1] = (dp[i + 1] + 15 * dp[i - 1] % mod) % mod;
          }
        }
      }
    }
    return dp[n];
  }
};
