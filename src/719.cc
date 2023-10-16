class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int min_val = 0;
    int max_val = nums.back() - nums.front();
    while (min_val < max_val) {
      const int mid_val = min_val + (max_val - min_val) / 2;
      int count = 0;
      for (int i = 0, j = 0; i < nums.size(); ++i) {
        while (j < nums.size() && nums[j] <= nums[i] + mid_val) {
          ++j;
        }
        count += j - i - 1;
      }
      if (count >= k) {
        max_val = mid_val;
      } else {
        min_val = mid_val + 1;
      }
    }
    return min_val;
  }
};
