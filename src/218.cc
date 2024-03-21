class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    const int n = buildings.size();
    vector<tuple<int, int, int>> events;
    events.reserve(n * 2);
    for (int i = 0; i < n; ++i) {
      events.emplace_back(buildings[i][0], i, 0);
      events.emplace_back(buildings[i][1], i, 1);
    }
    sort(events.begin(), events.end());
    vector<vector<int>> results;
    multiset<int> tree;
    tree.insert(0);
    int last_height = 0;
    for (int i = 0, j = 0; j <= events.size(); ++j) {
      if (j == events.size() || get<0>(events[j]) > get<0>(events[i])) {
        assert(!tree.empty());
        int current_height = *tree.rbegin();
        if (current_height != last_height) {
          results.push_back(vector<int>{get<0>(events[i]), current_height});
          last_height = current_height;
        }
        i = j;
      }
      if (j < events.size()) {
        const int height = buildings[get<1>(events[j])][2];
        if (get<2>(events[j]) == 0) {
          tree.insert(height);
        } else {
          auto it = tree.find(height);
          assert(it != tree.end());
          tree.erase(it);
        }
      }
    }
    return results;
  }
};
