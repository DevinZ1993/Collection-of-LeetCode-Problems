class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return solve(nums, k) - solve(nums, k - 1);
  }

 private:
  int solve(const vector<int>& nums, int k) const {
    unordered_map<int, int> cnts;
    int result = 0;
    for (int i = 0, j = 0; j < nums.size(); ++j) {
      ++cnts[nums[j]];
      while (cnts.size() > k) {
        auto it = cnts.find(nums[i]);
        assert(it != cnts.end());
        if (--it->second == 0) {
          cnts.erase(it);
        }
        ++i;
      }
      result += (j - i + 1);
    }
    return result;
  }
};
