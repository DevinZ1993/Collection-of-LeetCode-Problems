class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    const int n = nums.size();
    for (int i = n - 1; i > 0; --i) {
      if (nums[i - 1] < nums[i]) {
        int min_index = i;
        int max_index = n - 1;
        while (min_index < max_index) {
          const int mid_index = max_index - (max_index - min_index) / 2;
          if (nums[mid_index] <= nums[i - 1]) {
            max_index = mid_index - 1;
          } else {
            min_index = mid_index;
          }
        }
        swap(nums[i - 1], nums[min_index]);
        reverse(nums.begin() + i, nums.end());
        return;
      }
    }
    reverse(nums.begin(), nums.end());
  }
};
