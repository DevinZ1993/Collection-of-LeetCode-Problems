class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    constexpr array<pair<int, int>, 4> kDirs = {
        {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    const int m = matrix.size();
    const int n = matrix[0].size();
    int min_i = 0;
    int max_i = m - 1;
    int min_j = 0;
    int max_j = n - 1;
    int i = 0, j = 0, k = 0;
    vector<int> results;
    results.reserve(m * n);
    while (results.size() < m * n) {
      results.push_back(matrix[i][j]);
      const int next_i = i + kDirs[k].first;
      const int next_j = j + kDirs[k].second;
      if (next_i < min_i || next_i > max_i || next_j < min_j ||
          next_j > max_j) {
        if (k == 0) {
          ++min_i;
        } else if (k == 1) {
          --max_j;
        } else if (k == 2) {
          --max_i;
        } else {
          ++min_j;
        }
        k = (k + 1) % kDirs.size();
        i += kDirs[k].first;
        j += kDirs[k].second;
      } else {
        i = next_i;
        j = next_j;
      }
    }
    return results;
  }
};
