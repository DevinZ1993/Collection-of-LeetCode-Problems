class Solution {
 public:
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    vector<vector<pair<int, int>>> adjlists(n);
    for (int index = 0; index < connections.size(); ++index) {
      adjlists[connections[index][0]].emplace_back(index,
                                                   connections[index][1]);
      adjlists[connections[index][1]].emplace_back(index,
                                                   connections[index][0]);
    }
    vector<int> ranks(n, INT_MAX);
    ranks[0] = 0;
    unordered_set<int> cycle_edges;
    dfs(adjlists, 0, ranks, -1, cycle_edges);
    vector<vector<int>> results;
    for (int index = 0; index < connections.size(); ++index) {
      if (cycle_edges.count(index) == 0) {
        results.push_back(connections[index]);
      }
    }
    return results;
  }

 private:
  int dfs(const vector<vector<pair<int, int>>> &adjlists, int index,
          vector<int> &ranks, int parent, unordered_set<int> &cycle_edges) {
    int value = ranks[index];
    for (const auto [edge_index, next] : adjlists[index]) {
      if (next == parent) {
        continue;
      }
      int min_rank = ranks[next];
      if (min_rank == INT_MAX) {
        ranks[next] = ranks[index] + 1;
        min_rank = dfs(adjlists, next, ranks, index, cycle_edges);
      }
      if (min_rank <= ranks[index]) {
        cycle_edges.insert(edge_index);
      }
      value = min(value, min_rank);
    }
    return value;
  }
};
