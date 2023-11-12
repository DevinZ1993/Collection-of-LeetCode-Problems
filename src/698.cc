class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    long long sum = 0;
    for (int num : nums) {
      sum += num;
    }
    if (sum % k != 0) {
      return false;
    }
    const long long mod = sum / k;
    const int n = nums.size();
    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    for (int state = 1; state < dp.size(); ++state) {
      for (int i = 0; i < n; ++i) {
        if ((state & (1 << i)) != 0 && dp[state & ~(1 << i)] >= 0 &&
            dp[state & ~(1 << i)] + nums[i] <= mod) {
          dp[state] = (dp[state & ~(1 << i)] + nums[i]) % mod;
          break;
        }
      }
    }
    return dp.back() == 0;
  }
};
