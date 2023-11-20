class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> sums(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        sums[i + 1][j + 1] =
            (matrix[i][j] - '0') + sums[i + 1][j] + sums[i][j + 1] - sums[i][j];
      }
    }
    const auto get_sum = [&sums](int min_i, int min_j, int max_i, int max_j) {
      return sums[max_i + 1][max_j + 1] - sums[max_i + 1][min_j] -
             sums[min_i][max_j + 1] + sums[min_i][min_j];
    };

    int result = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i < result || j < result ||
            get_sum(i - result, j - result, i, j) <
                (result + 1) * (result + 1)) {
          continue;
        }
        int min_len = result + 1;
        int max_len = min(i, j) + 1;
        while (min_len < max_len) {
          const int mid_len = max_len - (max_len - min_len) / 2;
          if (get_sum(i - mid_len + 1, j - mid_len + 1, i, j) ==
              mid_len * mid_len) {
            min_len = mid_len;
          } else {
            max_len = mid_len - 1;
          }
        }
        result = min_len;
      }
    }
    return result * result;
  }
};
