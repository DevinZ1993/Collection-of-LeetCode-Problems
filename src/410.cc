class Solution {
 public:
  int splitArray(vector<int>& nums, int k) {
    int min_val = *max_element(nums.begin(), nums.end());
    int max_val = INT_MAX;
    while (min_val < max_val) {
      const int mid_val = min_val + (max_val - min_val) / 2;
      int count = 1;
      int sum = nums[0];
      for (int i = 1; i < nums.size(); ++i) {
        if (sum + nums[i] > mid_val) {
          ++count;
          sum = nums[i];
        } else {
          sum += nums[i];
        }
      }
      if (count <= k) {
        max_val = mid_val;
      } else {
        min_val = mid_val + 1;
      }
    }
    return min_val;
  }
};
