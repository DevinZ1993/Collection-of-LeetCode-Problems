class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    const int n = nums.size();
    int result = INT_MIN;
    int min_val = INT_MAX;
    for (int i = k, j = k;;) {
      min_val = min(min_val, min(nums[i], nums[j]));
      result = max(result, min_val * (j - i + 1));
      if (i == 0 && j == n - 1) {
        break;
      }
      if (j == n - 1 || (i > 0 && nums[i - 1] >= nums[j + 1])) {
        --i;
      } else {
        ++j;
      }
    }
    return result;
  }
};
