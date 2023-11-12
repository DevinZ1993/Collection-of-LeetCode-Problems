class Solution {
 public:
  int splitArray(vector<int>& nums, int k) {
    long long sum = 0;
    for (int num : nums) {
      sum += num;
    }
    int min_val = max<int>(sum / k, *max_element(nums.begin(), nums.end()));
    int max_val = static_cast<int>(min<long long>(INT_MAX, sum));
    while (min_val < max_val) {
      const int mid_val = min_val + (max_val - min_val) / 2;
      int sum = mid_val;
      int group = 0;
      for (int num : nums) {
        if (sum + num > mid_val) {
          ++group;
          sum = num;
        } else {
          sum += num;
        }
      }
      if (group <= k) {
        max_val = mid_val;
      } else {
        min_val = mid_val + 1;
      }
    }
    return min_val;
  }
};
