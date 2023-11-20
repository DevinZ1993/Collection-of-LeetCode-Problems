class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    sums_.resize(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        sums_[i + 1][j + 1] =
            matrix[i][j] + sums_[i + 1][j] + sums_[i][j + 1] - sums_[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return sums_[row2 + 1][col2 + 1] - sums_[row1][col2 + 1] -
           sums_[row2 + 1][col1] + sums_[row1][col1];
  }

 private:
  vector<vector<int>> sums_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
