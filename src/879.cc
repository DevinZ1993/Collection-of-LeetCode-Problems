class Solution {
 public:
  int profitableSchemes(int n, int minProfit, vector<int>& group,
                        vector<int>& profit) {
    constexpr int mod = 1'000'000'007;
    vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int index = 0; index < group.size(); ++index) {
      for (int i = n - group[index]; i >= 0; --i) {
        const int ii = i + group[index];
        for (int p = minProfit; p >= 0; --p) {
          const int pp = min(minProfit, p + profit[index]);
          dp[pp][ii] = (dp[pp][ii] + dp[p][i]) % mod;
        }
      }
    }
    int result = 0;
    for (int i = 0; i <= n; ++i) {
      result = (result + dp[minProfit][i]) % mod;
    }
    return result;
  }
};
