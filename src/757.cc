class Solution {
 public:
  int intersectionSizeTwo(vector<vector<int>> &intervals) {
    int last = -1;
    int second = -1;
    int result = 0;
    sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
      if (a[1] == b[1]) {
        return a[0] > b[0];
      }
      return a[1] < b[1];
    });
    for (const auto &interval : intervals) {
      if (second < interval[0]) {
        ++result;
        second = last;
        last = interval[1];
        if (second < interval[0]) {
          ++result;
          second = interval[1] - 1;
        }
      }
    }
    return result;
  }
};
