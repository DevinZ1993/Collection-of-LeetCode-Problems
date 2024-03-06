class Solution {
 public:
  int firstDayBeenInAllRooms(vector<int>& nextVisit) {
    constexpr int mod = 1'000'000'007;
    const int n = nextVisit.size();
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][1] = 1;
    for (int i = 1; i < n; ++i) {
      dp[i][0] = ((dp[i - 1][0] + dp[i - 1][1]) % mod + 1) % mod;
      dp[i][1] = ((1 + dp[i][0]) % mod + mod - dp[nextVisit[i]][0]) % mod;
    }
    return dp[n - 1][0];
  }
};
