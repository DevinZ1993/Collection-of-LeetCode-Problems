class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<long long>> sums(m + 1, vector<long long>(n + 1));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        sums[i + 1][j + 1] =
            sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + matrix[i][j];
      }
    }
    long long result = LLONG_MIN;
    set<long long> tree;
    for (int min_j = 0; min_j < n; ++min_j) {
      for (int max_j = min_j; max_j < n; ++max_j) {
        tree.clear();
        tree.insert(0);
        for (int i = 0; i < m; ++i) {
          const long long sum = sums[i + 1][max_j + 1] - sums[i + 1][min_j] -
                                sums[0][max_j + 1] + sums[0][min_j];
          if (auto it = tree.lower_bound(sum - k); it != tree.end()) {
            result = max(result, sum - *it);
          }
          tree.insert(sum);
        }
      }
    }
    return result;
  }
};
