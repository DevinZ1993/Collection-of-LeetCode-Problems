class Solution {
 public:
  int maxWidthRamp(vector<int>& nums) {
    const int n = nums.size();
    vector<int> lefts;
    vector<int> rights;
    for (int i = 0; i < n; ++i) {
      if (lefts.empty() || nums[i] < nums[lefts.back()]) {
        lefts.push_back(i);
      }
      while (!rights.empty() && nums[rights.back()] < nums[i]) {
        rights.pop_back();
      }
      rights.push_back(i);
    }
    int result = 0;
    for (int i = 0, j = 0; i < lefts.size() && j < rights.size(); ++i) {
      while (j < rights.size() && nums[lefts[i]] <= nums[rights[j]]) {
        result = max(result, rights[j] - lefts[i]);
        ++j;
      }
    }
    return result;
  }
};
