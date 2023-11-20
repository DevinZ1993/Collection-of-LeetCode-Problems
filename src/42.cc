class Solution {
 public:
  int trap(vector<int>& height) {
    const int n = height.size();
    int result = 0;
    int left_max = 0;
    int right_max = 0;
    for (int i = 0, j = n - 1; i <= j;) {
      if (left_max < right_max) {
        result += max(0, left_max - height[i]);
        left_max = max(left_max, height[i++]);
      } else {
        result += max(0, right_max - height[j]);
        right_max = max(right_max, height[j--]);
      }
    }
    return result;
  }
};
