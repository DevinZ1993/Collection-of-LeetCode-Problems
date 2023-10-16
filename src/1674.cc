class Solution {
 public:
  int minMoves(vector<int>& nums, int limit) {
    vector<int> diffs(2 * limit + 2);
    for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
      const int min_val = min(nums[i], nums[j]);
      const int max_val = max(nums[i], nums[j]);
      if (max_val > 1) {
        diffs[2] += 2;
        diffs[min_val + 1] -= 2;
      }
      if (limit > 1) {
        ++diffs[min_val + 1];
        --diffs[min_val + max_val];
        ++diffs[min_val + max_val + 1];
        --diffs[max_val + limit + 1];
      }
      if (min_val < limit) {
        diffs[max_val + limit + 1] += 2;
        diffs[limit * 2 + 1] -= 2;
      }
    }
    int result = INT_MAX;
    int sum = 0;
    for (int i = 2; i <= limit * 2; ++i) {
      sum += diffs[i];
      result = min(result, sum);
    }
    return result;
  }
};
