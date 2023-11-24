class Solution {
 public:
  int minTaps(int n, vector<int>& ranges) {
    vector<pair<int, int>> intervals;
    intervals.reserve(n + 1);
    for (int i = 0; i <= n; ++i) {
      intervals.emplace_back(max(0, i - ranges[i]), min(n, i + ranges[i]));
    }
    sort(intervals.begin(), intervals.end());
    int max_covered = -1;
    int result = 0;
    for (int i = 1, j = 0; i <= n; ++i) {
      if (max_covered >= i) {
        continue;
      }
      while (j < intervals.size() && intervals[j].first < i) {
        max_covered = max(max_covered, intervals[j].second);
        ++j;
      }
      if (max_covered < i) {
        return -1;
      }
      ++result;
    }
    return result;
  }
};
