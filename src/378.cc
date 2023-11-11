class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    const int n = matrix.size();
    int min_val = matrix[0][0];
    int max_val = matrix[n - 1][n - 1];
    while (min_val < max_val) {
      const int mid_val = min_val + (max_val - min_val) / 2;
      int count = 0;
      for (int i = n - 1, j = 0; i >= 0; --i) {
        while (j < n && matrix[i][j] <= mid_val) {
          ++j;
        }
        count += j;
      }
      if (count >= k) {
        max_val = mid_val;
      } else {
        min_val = mid_val + 1;
      }
    }
    return min_val;
  }
};
