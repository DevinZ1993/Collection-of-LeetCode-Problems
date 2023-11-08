class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    const int n = nums.size();
    int min_index = 0;
    int max_index = n - 1;
    while (min_index <= max_index) {
      const int mid_index = min_index + (max_index - min_index) / 2;
      if (nums[mid_index] == target) {
        return true;
      }
      if (nums[min_index] < nums[max_index]) {
        return binary_search(nums.begin() + min_index,
                             nums.begin() + max_index + 1, target);
      }
      if (target >= nums[min_index] && target < nums[mid_index]) {
        return binary_search(nums.begin() + min_index, nums.begin() + mid_index,
                             target);
      }
      if (target > nums[mid_index] && target <= nums[max_index]) {
        return binary_search(nums.begin() + mid_index + 1,
                             nums.begin() + max_index + 1, target);
      }

      if (nums[min_index] == nums[mid_index] &&
          nums[max_index] == nums[mid_index]) {
        ++min_index;
        --max_index;
        continue;
      }

      if (nums[mid_index] >= nums[min_index]) {
        min_index = mid_index + 1;
      } else {
        max_index = mid_index - 1;
      }
    }
    return false;
  }
};
