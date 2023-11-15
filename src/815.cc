class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int source,
                            int target) {
    if (source == target) {
      return 0;
    }
    unordered_map<int, vector<int>> indices;
    for (int i = 0; i < routes.size(); ++i) {
      for (int index : routes[i]) {
        indices[index].push_back(i);
      }
    }
    unordered_set<int> target_buses(indices[target].begin(),
                                    indices[target].end());
    vector<int> dists(routes.size(), INT_MAX);
    unordered_set<int> vis_stops;
    deque<int> q;
    for (int bus_index : indices[source]) {
      if (target_buses.count(bus_index) > 0) {
        return 1;
      }
      q.emplace_back(bus_index);
      dists[bus_index] = 1;
    }
    vis_stops.insert(source);
    while (!q.empty()) {
      const int bus_index = q.front();
      q.pop_front();
      for (int stop : routes[bus_index]) {
        if (vis_stops.count(stop)) {
          continue;
        }
        vis_stops.insert(stop);
        for (int next_bus : indices[stop]) {
          if (target_buses.count(next_bus) > 0) {
            return dists[bus_index] + 1;
          }
          if (dists[next_bus] == INT_MAX) {
            dists[next_bus] = dists[bus_index] + 1;
            q.push_back(next_bus);
          }
        }
      }
    }
    return -1;
  }
};
