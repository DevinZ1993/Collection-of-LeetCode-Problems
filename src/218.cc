class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    map<int, vector<pair<int, int>>> events;
    for (const auto &building : buildings) {
      events[building[0]].emplace_back(building[2], 0);
      events[building[1]].emplace_back(building[2], 1);
    }
    vector<vector<int>> results;
    multiset<int> heights;
    for (const auto &[x, sub_events] : events) {
      const int last_height = heights.empty() ? 0 : *heights.rbegin();
      for (const auto &[height, state] : sub_events) {
        if (state == 0) {
          heights.insert(height);
        } else {
          auto it = heights.find(height);
          assert(it != heights.end());
          heights.erase(it);
        }
      }
      const int height = heights.empty() ? 0 : *heights.rbegin();
      if (height != last_height) {
        results.push_back(vector<int>{x, height});
      }
    }
    return results;
  }
};
