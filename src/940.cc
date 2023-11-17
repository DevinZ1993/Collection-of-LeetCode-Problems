class Solution {
 public:
  int distinctSubseqII(string s) {
    constexpr int mod = 1'000'000'007;
    array<int, 26> last_dp{};
    array<int, 26> dp{};
    dp[s[0] - 'a'] = 1;
    int sum = 1;
    for (int i = 1; i < s.size(); ++i) {
      last_dp = dp;
      dp[s[i] - 'a'] = (sum + 1) % mod;
      sum = 0;
      for (int j = 0; j < dp.size(); ++j) {
        sum = (sum + dp[j]) % mod;
      }
    }
    return sum;
  }
};
