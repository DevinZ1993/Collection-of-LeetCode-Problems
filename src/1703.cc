class Solution {
 public:
  int minMoves(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<long long> sums;
    sums.push_back(0);
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        sums.push_back(sums.back() + i);
      }
    }
    long long result = LLONG_MAX;
    for (int i = 0; i + k < sums.size(); ++i) {
      result = min(result, sums[i + k] - sums[i + (k + 1) / 2] -
                               sums[i + k / 2] + sums[i]);
    }
    result -= (1LL + k) / 2 * (k / 2LL);
    return result;
  }
};
