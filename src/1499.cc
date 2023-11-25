class Solution {
 public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    deque<int> q;
    int result = INT_MIN;
    for (int i = 0; i < points.size(); ++i) {
      while (!q.empty() && points[q.front()][0] < points[i][0] - k) {
        q.pop_front();
      }
      if (!q.empty()) {
        result = max(result, points[q.front()][1] - points[q.front()][0] +
                                 points[i][0] + points[i][1]);
      }
      while (!q.empty() && points[q.back()][1] - points[q.back()][0] <=
                               points[i][1] - points[i][0]) {
        q.pop_back();
      }
      q.push_back(i);
    }
    return result;
  }
};
