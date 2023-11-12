class Solution {
 public:
  int removeBoxes(vector<int> &boxes) {
    const int n = boxes.size();
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(n, vector<int>(n, -1)));
    return solve(boxes, dp, n, 0, 0);
  }

 private:
  int solve(const vector<int> &boxes, vector<vector<vector<int>>> &memo,
            int len, int i, int k) {
    if (len == 0) {
      return k * k;
    }
    auto &val = memo[len - 1][i][k];
    if (val < 0) {
      val = solve(boxes, memo, len - 1, i, 0) + (k + 1) * (k + 1);
      for (int j = i; j < i + len - 1; ++j) {
        if (boxes[j] == boxes[i + len - 1]) {
          val = max(val, solve(boxes, memo, j - i + 1, i, k + 1) +
                             solve(boxes, memo, i + len - j - 2, j + 1, 0));
        }
      }
    }
    return val;
  }
};
