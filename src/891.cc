class Solution {
 public:
  int sumSubseqWidths(vector<int>& nums) {
    constexpr long long mod = 1'000'000'007LL;
    const int n = nums.size();
    vector<long long> pows(n + 1);
    pows[0] = 1;
    for (int i = 1; i <= n; ++i) {
      pows[i] = pows[i - 1] * 2 % mod;
    }
    sort(nums.begin(), nums.end());
    long long result = 0;
    for (int i = 0; i < n; ++i) {
      result = (result + nums[i] * pows[i] % mod) % mod;
      result = (result + mod - nums[i] * pows[n - i - 1] % mod) % mod;
    }
    return result;
  }
};
