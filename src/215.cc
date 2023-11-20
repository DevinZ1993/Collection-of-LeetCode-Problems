class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    const int n = nums.size();
    const int target_index = n - k;
    random_shuffle(nums.begin(), nums.end());
    for (int min_index = 0, max_index = n - 1; min_index <= max_index;) {
      int i = min_index;
      int j = min_index;
      int k = max_index;
      while (j < k) {
        if (nums[j] < nums[max_index]) {
          swap(nums[i++], nums[j++]);
        } else if (nums[j] == nums[max_index]) {
          ++j;
        } else {
          swap(nums[j], nums[--k]);
        }
      }
      swap(nums[j], nums[max_index]);
      if (target_index >= i && target_index <= j) {
        return nums[i];
      } else if (target_index < i) {
        max_index = i - 1;
      } else {
        min_index = j + 1;
      }
    }
    return -1;
  }
};
