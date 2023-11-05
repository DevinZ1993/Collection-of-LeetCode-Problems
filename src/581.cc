class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    int last = -1;
    for (int i = 1, max_val = nums[0]; i < nums.size(); ++i) {
      max_val = max(max_val, nums[i]);
      if (nums[i] < max_val) {
        last = i;
      }
    }
    if (last < 0) {
      return 0;
    }
    const int n = nums.size();
    int first = n;
    for (int i = n - 2, min_val = nums.back(); i >= 0; --i) {
      min_val = min(min_val, nums[i]);
      if (nums[i] > min_val) {
        first = i;
      }
    }
    return last - first + 1;
  }
};
