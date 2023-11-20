class Solution {
 public:
  void sortColors(vector<int>& nums) {
    array<int, 3> cnts{};
    for (int num : nums) {
      ++cnts[num];
    }
    for (int i = 0, j = 0; i < nums.size(); ++i) {
      while (cnts[j] == 0) {
        ++j;
      }
      --cnts[j];
      nums[i] = j;
    }
  }
};
