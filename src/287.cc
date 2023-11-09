class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    const int n = nums.size() - 1;
    int i = n;
    int j = n;
    while (true) {
      i = nums[i] - 1;
      j = nums[nums[j] - 1] - 1;
      if (i == j) {
        break;
      }
    }
    i = n;
    while (i != j) {
      i = nums[i] - 1;
      j = nums[j] - 1;
    }
    return i + 1;
  }
};
