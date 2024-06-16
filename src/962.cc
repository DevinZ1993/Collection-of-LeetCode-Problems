class Solution {
 public:
  int maxWidthRamp(vector<int>& nums) {
    const int n = nums.size();
    vector<int> lefts;
    vector<int> rights;
    for (int i = 0; i < n; ++i) {
      if (lefts.empty() || nums[lefts.back()] > nums[i]) {
        lefts.push_back(i);
      }
      while (!rights.empty() && nums[rights.back()] <= nums[i]) {
        rights.pop_back();
      }
      rights.push_back(i);
    }
    int result = 0;
    while (!rights.empty()) {
      const int j = rights.back();
      rights.pop_back();
      while (!lefts.empty() && lefts.back() >= j) {
        lefts.pop_back();
      }
      while (!lefts.empty() && nums[lefts.back()] <= nums[j]) {
        result = max(result, j - lefts.back());
        lefts.pop_back();
      }
    }
    return result;
  }
};
