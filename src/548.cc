class Solution {
 public:
  bool splitArray(vector<int>& nums) {
    const int n = nums.size();
    vector<long long> sums(n + 1);
    for (int i = 0; i < n; ++i) {
      sums[i + 1] = sums[i] + nums[i];
    }
    unordered_set<long long> left_sums;
    for (int j = 3; j + 3 < n; ++j) {
      left_sums.clear();
      for (int i = 1; i + 1 < j; ++i) {
        const long long sum = sums[i];
        if (sum == sums[j] - sums[i + 1]) {
          left_sums.insert(sum);
        }
      }
      for (int k = j + 2; k + 1 < n; ++k) {
        const long long sum = sums[k] - sums[j + 1];
        if (sum == sums[n] - sums[k + 1] && left_sums.count(sum) > 0) {
          return true;
        }
      }
    }
    return false;
  }
};
