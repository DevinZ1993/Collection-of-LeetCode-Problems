class Solution {
 public:
  int countSubranges(vector<int>& nums1, vector<int>& nums2) {
    constexpr int mod = 1'000'000'007;
    unordered_map<int, int> dp;
    unordered_map<int, int> last_dp;
    int result = 0;
    for (int i = 0; i < nums1.size(); ++i) {
      swap(dp, last_dp);
      dp.clear();
      ++dp[nums1[i]];
      ++dp[-nums2[i]];
      for (const auto& [val, cnt] : last_dp) {
        dp[val + nums1[i]] = (dp[val + nums1[i]] + cnt) % mod;
        dp[val - nums2[i]] = (dp[val - nums2[i]] + cnt) % mod;
      }
      if (auto it = dp.find(0); it != dp.end()) {
        result = (result + it->second) % mod;
      }
    }
    return result;
  }
};
