class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    vector<vector<int>> results;
    int index = 0;
    for (; index < intervals.size() && intervals[index][1] < newInterval[0];
         ++index) {
      results.emplace_back(move(intervals[index]));
    }
    results.emplace_back(move(newInterval));
    for (; index < intervals.size(); ++index) {
      auto& result = results.back();
      if (result[1] < intervals[index][0]) {
        results.emplace_back(move(intervals[index]));
      } else {
        result[0] = min(result[0], intervals[index][0]);
        result[1] = max(result[1], intervals[index][1]);
      }
    }
    return results;
  }
};
