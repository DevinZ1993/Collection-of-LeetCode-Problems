class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    const int n = nums.size();
    const auto get_num = [&nums](int i) {
      if (i < 0 || i >= nums.size()) {
        return 1;
      }
      return nums[i];
    };
    vector<vector<int>> dp(n);
    for (int len = 1; len <= n; ++len) {
      dp[len - 1].resize(n - len + 1);
      for (int i = 0; i + len <= n; ++i) {
        for (int j = i; j < i + len; ++j) {
          dp[len - 1][i] =
              max(dp[len - 1][i],
                  get_num(i - 1) * nums[j] * get_num(i + len) +
                      (j == i ? 0 : dp[j - i - 1][i]) +
                      (j + 1 == i + len ? 0 : dp[i + len - 2 - j][j + 1]));
        }
      }
    }
    return dp[n - 1][0];
  }
};
