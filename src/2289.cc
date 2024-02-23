class Solution {
 public:
  int totalSteps(vector<int>& nums) {
    const int n = nums.size();
    vector<int> dp(n + 1, 1);
    vector<int> stk;
    int result = 0;
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && nums[stk.back()] <= nums[i]) {
        dp[i] = max(dp[i], 1 + dp[stk.back()]);
        stk.pop_back();
      }
      if (!stk.empty()) {
        result = max(result, dp[i]);
      }
      stk.push_back(i);
    }
    return result;
  }
};
