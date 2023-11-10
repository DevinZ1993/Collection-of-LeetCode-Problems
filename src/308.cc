class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& matrix) {
    fenwick_.resize(matrix.size() + 1);
    if (!matrix.empty()) {
      for (auto& row : fenwick_) {
        row.resize(matrix[0].size() + 1);
      }
    }
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        update(i, j, matrix[i][j]);
      }
    }
  }

  void update(int row, int col, int val) {
    const int delta = val - sumRegion(row, col, row, col);
    for (int i = row + 1; i < fenwick_.size(); i += (i & (-i))) {
      for (int j = col + 1; j < fenwick_[i].size(); j += (j & (-j))) {
        fenwick_[i][j] += delta;
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return getSum(row2, col2) - getSum(row1 - 1, col2) -
           getSum(row2, col1 - 1) + getSum(row1 - 1, col1 - 1);
  }

 private:
  int getSum(int row, int col) const {
    int result = 0;
    for (int i = row + 1; i > 0; i &= (i - 1)) {
      for (int j = col + 1; j > 0; j &= (j - 1)) {
        result += fenwick_[i][j];
      }
    }
    return result;
  }

  vector<vector<int>> fenwick_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
