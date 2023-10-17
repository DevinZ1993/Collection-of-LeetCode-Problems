class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    const int n = nums.size();
    if (n < 3) {
      return false;
    }
    int min_i = nums[0];
    int max_j = INT_MIN;
    vector<pair<int, int>> stk;
    for (int i = 1; i < n; ++i) {
      if (nums[i] > min_i && nums[i] < max_j) {
        return true;
      }
      if (nums[i] < min_i) {
        if (min_i < max_j) {
          stk.emplace_back(min_i, max_j);
        }
        min_i = nums[i];
        max_j = INT_MIN;
        continue;
      }
      max_j = max(max_j, nums[i]);
      while (!stk.empty() && max_j >= stk.back().second) {
        stk.pop_back();
      }
      if (!stk.empty() && nums[i] > stk.back().first) {
        return true;
      }
    }
    return false;
  }
};
