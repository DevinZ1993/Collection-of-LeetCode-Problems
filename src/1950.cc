class Solution {
 public:
  vector<int> findMaximums(vector<int>& nums) {
    const int n = nums.size();
    vector<int> stk;
    vector<int> lefts(n, -1);
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && nums[stk.back()] >= nums[i]) {
        stk.pop_back();
      }
      if (!stk.empty()) {
        lefts[i] = stk.back();
      }
      stk.push_back(i);
    }
    vector<int> rights(n, n);
    stk.clear();
    for (int i = n - 1; i >= 0; --i) {
      while (!stk.empty() && nums[stk.back()] >= nums[i]) {
        stk.pop_back();
      }
      if (!stk.empty()) {
        rights[i] = stk.back();
      }
      stk.push_back(i);
    }
    vector<int> results(n);
    for (int i = 0; i < n; ++i) {
      const int span = rights[i] - lefts[i] - 1;
      results[span - 1] = max(results[span - 1], nums[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
      results[i] = max(results[i], results[i + 1]);
    }
    return results;
  }
};
