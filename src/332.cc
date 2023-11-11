class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    unordered_map<string, multiset<string>> adj_lists;
    for (const auto &ticket : tickets) {
      adj_lists[ticket[0]].insert(ticket[1]);
    }
    vector<string> path;
    vector<string> stk;
    stk.push_back("JFK");
    while (!stk.empty()) {
      const string &city = stk.back();
      auto it = adj_lists.find(city);
      if (it == adj_lists.end() || it->second.empty()) {
        path.push_back(city);
        stk.pop_back();
        continue;
      }
      auto next_city_it = it->second.begin();
      stk.push_back(*next_city_it);
      it->second.erase(next_city_it);
    }
    reverse(path.begin(), path.end());
    return path;
  }
};
