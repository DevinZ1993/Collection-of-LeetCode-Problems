class Solution {
 public:
  int search(vector<int>& nums, int target) {
    for (int i = 0, j = nums.size() - 1; i <= j;) {
      if (nums[i] < nums[j]) {
        const auto it =
            lower_bound(nums.begin() + i, nums.begin() + j + 1, target);
        if (it == nums.begin() + j + 1 || *it > target) {
          return -1;
        }
        return distance(nums.begin(), it);
      }
      const int mid_index = i + (j - i) / 2;
      if (nums[mid_index] == target) {
        return mid_index;
      }
      if (nums[mid_index] >= nums[i]) {
        if (target > nums[mid_index] || target < nums[i]) {
          i = mid_index + 1;
        } else {
          j = mid_index - 1;
        }
      } else {
        if (target < nums[mid_index] || target > nums[j]) {
          j = mid_index - 1;
        } else {
          i = mid_index + 1;
        }
      }
    }
    return -1;
  }
};
