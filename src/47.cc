class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    unordered_map<int, int> cnts;
    for (int num : nums) {
      ++cnts[num];
    }
    vector<vector<int>> results;
    vector<int> result;
    result.reserve(nums.size());
    vector<tuple<int, int, int>> stk;
    stk.emplace_back(0, 0, 0);
    while (!stk.empty()) {
      auto [index, val, state] = stk.back();
      stk.pop_back();
      if (index == nums.size()) {
        results.push_back(result);
        continue;
      }
      if (state < 0) {
        ++cnts[val];
        result.pop_back();
        continue;
      }
      if (state > 0) {
        stk.emplace_back(index, val, -1);
        --cnts[val];
        result.push_back(val);
        stk.emplace_back(index + 1, 0, 0);
        continue;
      }
      for (const auto [val, cnt] : cnts) {
        if (cnt > 0) {
          stk.emplace_back(index, val, 1);
        }
      }
    }
    return results;
  }
};
