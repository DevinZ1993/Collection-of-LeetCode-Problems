class Solution {
 public:
  int beautifulPartitions(string s, int k, int minLength) {
    constexpr auto is_prime = [](char ch) {
      return ch == '2' || ch == '3' || ch == '5' || ch == '7';
    };
    constexpr int mod = 1'000'000'007;
    const int n = s.size();
    vector<int> dp(n + 1);
    vector<int> last_dp(n + 1);
    dp[0] = 1;
    while (k-- > 0) {
      swap(dp, last_dp);
      int sum = 0;
      dp[0] = 0;
      for (int i = 0, j = 1; j <= n; ++j) {
        if (is_prime(s[j - 1])) {
          continue;
        }
        while (j - i >= minLength) {
          if (is_prime(s[i])) {
            sum = (sum + last_dp[i]) % mod;
          }
          ++i;
        }
        dp[j] = sum;
      }
    }
    return dp[n];
  }
};
