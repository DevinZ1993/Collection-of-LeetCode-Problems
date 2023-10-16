class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    const int n = heights.size();
    vector<int> lefts(n, -1);
    vector<int> stk;
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && heights[stk.back()] >= heights[i]) {
        stk.pop_back();
      }
      if (!stk.empty()) {
        lefts[i] = stk.back();
      }
      stk.push_back(i);
    }

    vector<int> rights(n, n);
    stk.clear();
    for (int i = n - 1; i >= 0; --i) {
      while (!stk.empty() && heights[stk.back()] >= heights[i]) {
        stk.pop_back();
      }
      if (!stk.empty()) {
        rights[i] = stk.back();
      }
      stk.push_back(i);
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
      result = max(result, heights[i] * (rights[i] - lefts[i] - 1));
    }
    return result;
  }
};
