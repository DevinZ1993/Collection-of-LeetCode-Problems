class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    int result = 0;
    vector<int> heights(n);
    vector<int> lefts(n);
    vector<int> rights(n);
    vector<int> stk;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
      }
      stk.clear();
      for (int j = 0; j < n; ++j) {
        while (!stk.empty() && heights[stk.back()] >= heights[j]) {
          stk.pop_back();
        }
        lefts[j] = stk.empty() ? -1 : stk.back();
        stk.push_back(j);
      }
      stk.clear();
      for (int j = n - 1; j >= 0; --j) {
        while (!stk.empty() && heights[stk.back()] >= heights[j]) {
          stk.pop_back();
        }
        rights[j] = stk.empty() ? n : stk.back();
        stk.push_back(j);
      }
      for (int j = 0; j < n; ++j) {
        result = max(result, heights[j] * (rights[j] - lefts[j] - 1));
      }
    }
    return result;
  }
};
