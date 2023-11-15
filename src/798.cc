class Solution {
 public:
  int bestRotation(vector<int>& nums) {
    const int n = nums.size();
    vector<int> sums(n + 1);
    for (int i = 0; i < n; ++i) {
      if (nums[i] > i) {
        ++sums[i + 1];
        --sums[i + 1 + n - nums[i]];
      } else {
        ++sums[i + 1];
        --sums[n];
        ++sums[0];
        --sums[i - nums[i] + 1];
      }
    }
    int index = 0;
    for (int i = 1; i < n; ++i) {
      sums[i] += sums[i - 1];
      if (sums[i] > sums[index]) {
        index = i;
      }
    }
    return index;
  }
};
