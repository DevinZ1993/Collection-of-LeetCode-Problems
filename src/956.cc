class Solution {
 public:
  int tallestBillboard(vector<int> &rods) {
    unordered_map<int, int> dp;
    dp.emplace(0, 0);
    unordered_map<int, int> last_dp;
    for (int rod : rods) {
      last_dp = dp;
      for (const auto &[k, v] : last_dp) {
        for (int kk : vector<int>{k + rod, k - rod}) {
          auto &val = dp[kk];
          val = max(val, v + rod);
        }
      }
    }
    return dp[0] / 2;
  }
};
