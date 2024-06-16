class Solution {
 public:
  int superEggDrop(int k, int n) {
    vector<int> last_dp(n + 1);
    vector<int> current_dp(n + 1);
    iota(current_dp.begin(), current_dp.end(), 0);
    for (int kk = 2; kk <= k; ++kk) {
      swap(last_dp, current_dp);
      for (int nn = 1, i = 1; nn <= n; ++nn) {
        while (i <= nn && last_dp[i - 1] < current_dp[nn - i]) {
          ++i;
        }
        current_dp[nn] = INT_MAX;
        if (i > 1) {
          current_dp[nn] = current_dp[nn - i + 1] + 1;
        }
        if (i <= nn) {
          current_dp[nn] = min(current_dp[nn], last_dp[i - 1] + 1);
        }
      }
    }
    return current_dp[n];
  }
};
