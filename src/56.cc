class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> results;
    for (const auto& interval : intervals) {
      if (results.empty() || results.back()[1] < interval[0]) {
        results.push_back(interval);
      } else {
        results.back()[1] = max(results.back()[1], interval[1]);
      }
    }
    return results;
  }
};
