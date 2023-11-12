class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    double min_val = *min_element(nums.begin(), nums.end());
    double max_val = *max_element(nums.begin(), nums.end());
    while (max_val > min_val + 1.0e-5) {
      const double mid_val = 0.5 * (min_val + max_val);
      bool flag = false;
      double left_sum = 0.0;
      double right_sum = 0.0;
      double min_left = 0.0;
      for (int i = 0; i < nums.size(); ++i) {
        if (i >= k) {
          left_sum += nums[i - k] - mid_val;
          min_left = min(min_left, left_sum);
        }
        right_sum += nums[i] - mid_val;
        if (i >= k - 1 && right_sum >= min_left) {
          flag = true;
          break;
        }
      }
      if (flag) {
        min_val = mid_val;
      } else {
        max_val = mid_val;
      }
    }
    return 0.5 * (min_val + max_val);
  }
};
