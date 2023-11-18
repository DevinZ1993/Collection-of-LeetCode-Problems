class Solution {
 public:
  int leastOpsExpressTarget(int x, int target) {
    vector<int> factors;
    for (int value = target; value > 0; value /= x) {
      factors.push_back(value % x);
    }

    constexpr auto eval = [](int n) { return n == 0 ? 2 : n; };

    vector<int> last_dp(2);
    vector<int> dp(2);
    dp[1] = eval(factors.size());
    for (int i = factors.size() - 1; i >= 0; --i) {
      swap(dp, last_dp);
      dp[0] = min(last_dp[0] + eval(i) * factors[i],
                  last_dp[1] + eval(i) * (x - factors[i]));
      dp[1] = min(last_dp[0] + eval(i) * (factors[i] + 1),
                  last_dp[1] + eval(i) * (x - 1 - factors[i]));
    }
    return dp[0] - 1;
  }
};
