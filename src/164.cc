class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    const int n = nums.size();
    vector<int> zeros;
    vector<int> ones;
    zeros.reserve(n);
    ones.reserve(n);
    for (int offset = 0; offset < 31; ++offset) {
      const int bit = (1 << offset);
      zeros.clear();
      ones.clear();
      for (int num : nums) {
        if (num & bit) {
          ones.push_back(num);
        } else {
          zeros.push_back(num);
        }
      }
      nums.clear();
      for (int num : zeros) {
        nums.push_back(num);
      }
      for (int num : ones) {
        nums.push_back(num);
      }
    }
    int result = 0;
    for (int i = 1; i < n; ++i) {
      result = max(result, nums[i] - nums[i - 1]);
    }
    return result;
  }
};
