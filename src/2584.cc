class Solution {
 public:
  int findValidSplit(vector<int>& nums) {
    array<int, 1'000'001> factors{};
    factors[1] = 1;
    for (int i = 2; i < factors.size(); ++i) {
      if (factors[i] != 0) {
        continue;
      }
      for (int j = i; j < factors.size(); j += i) {
        factors[j] = i;
      }
    }
    unordered_map<int, int> right;
    for (int num : nums) {
      while (num > 1) {
        const int factor = factors[num];
        ++right[factor];
        num /= factor;
      }
    }
    unordered_map<int, int> left;
    int common = 0;
    for (int i = 0; i + 1 < nums.size(); ++i) {
      int num = nums[i];
      while (num > 1) {
        const int factor = factors[num];
        const int left_cnt = left[factor];
        const int right_cnt = right[factor];
        if (right_cnt == 1 && left_cnt > 0) {
          --common;
        } else if (left_cnt == 0 && right_cnt > 1) {
          ++common;
        }
        ++left[factor];
        --right[factor];
        num /= factor;
      }
      if (common == 0) {
        return i;
      }
    }
    return -1;
  }
};
