class Solution {
 public:
  int numDecodings(string s) {
    constexpr long long mod = 1'000'000'007LL;
    vector<long long> dp(s.size() + 1);
    dp[0] = 1;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0') {
        dp[i + 1] = 0;
      } else if (s[i] == '*') {
        dp[i + 1] = 9 * dp[i] % mod;
      } else {
        dp[i + 1] = dp[i];
      }
      if (i > 0 && (s[i - 1] == '1' || s[i - 1] == '*')) {
        if (s[i] == '*') {
          dp[i + 1] = (dp[i + 1] + dp[i - 1] * 9 % mod) % mod;
        } else {
          dp[i + 1] = (dp[i + 1] + dp[i - 1]) % mod;
        }
      }
      if (i > 0 && (s[i - 1] == '2' || s[i - 1] == '*')) {
        if (s[i] == '*') {
          dp[i + 1] = (dp[i + 1] + dp[i - 1] * 6 % mod) % mod;
        } else if (s[i] <= '6') {
          dp[i + 1] = (dp[i + 1] + dp[i - 1]) % mod;
        }
      }
    }
    return dp.back();
  }
};
