class Solution {
 public:
  int minChanges(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> dp(1 << 10, INT_MAX);
    vector<int> last_dp(1 << 10);
    dp[0] = 0;
    unordered_map<int, int> cnts;
    for (int i = 0; i < k; ++i) {
      swap(dp, last_dp);
      cnts.clear();
      int total_cnt = 0;
      for (int j = i; j < n; j += k) {
        ++cnts[nums[j]];
        ++total_cnt;
      }
      const int min_val = *min_element(last_dp.begin(), last_dp.end());
      fill(dp.begin(), dp.end(), total_cnt + min_val);
      for (int state = 0; state < last_dp.size(); ++state) {
        if (last_dp[state] == INT_MAX) {
          continue;
        }
        for (const auto& [v, cnt] : cnts) {
          const int next = (state ^ v);
          dp[next] = min(dp[next], last_dp[state] + total_cnt - cnt);
        }
      }
    }
    return dp[0];
  }
};
