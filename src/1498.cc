class Solution {
 public:
  int numSubseq(vector<int>& nums, int target) {
    constexpr long long mod = 1'000'000'007;
    vector<long long> pows(nums.size() + 1);
    pows[0] = 1;
    for (int i = 1; i < pows.size(); ++i) {
      pows[i] = (pows[i - 1] << 1) % mod;
    }

    sort(nums.begin(), nums.end());
    long long result = 0;
    for (int i = 0, j = nums.size() - 1; j >= 0; --j) {
      while (i <= j && nums[i] + nums[j] <= target) {
        ++i;
      }
      if (i > j) {
        result = (result + pows[j]) % mod;
      } else {
        result = (result + (pows[i] + mod - 1) % mod * pows[j - i] % mod) % mod;
      }
    }
    return result;
  }
};
