class Solution {
 public:
  int numMusicPlaylists(int n, int goal, int k) {
    constexpr long long mod = 1'000'000'007LL;
    vector<vector<long long>> combs(2, vector<long long>(n + 1));
    combs[0][0] = combs[1][0] = 1;
    for (int i = 1; i <= n; ++i) {
      const int index = i % 2;
      for (int j = 1; j < i; ++j) {
        combs[index][j] = (combs[1 - index][j] + combs[1 - index][j - 1]) % mod;
      }
      combs[index][i] = 1;
    }
    vector<long long> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
      dp[i] = i;
      for (int j = 1; j < goal; ++j) {
        dp[i] = max(0, i - min(k, j)) * dp[i] % mod;
      }
    }
    long long result = dp[n];
    for (int i = n - 1; i >= 1; --i) {
      if (i % 2 == n % 2) {
        result = (result + combs[n % 2][n - i] * dp[i] % mod) % mod;
      } else {
        result = (result + mod - combs[n % 2][n - i] * dp[i] % mod) % mod;
      }
    }
    return result;
  }
};
