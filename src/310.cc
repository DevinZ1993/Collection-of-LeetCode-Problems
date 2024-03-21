class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n <= 2) {
      return (n == 1 ? vector<int>{0} : vector<int>{0, 1});
    }
    vector<unordered_set<int>> adjlists(n);
    for (const auto& edge : edges) {
      adjlists[edge[0]].insert(edge[1]);
      adjlists[edge[1]].insert(edge[0]);
    }
    unordered_set<int> visited;
    vector<int> leaves;
    for (int i = 0; i < n; ++i) {
      if (adjlists[i].size() == 1) {
        leaves.push_back(i);
        visited.insert(i);
      }
    }
    vector<int> nexts;
    while (visited.size() < n) {
      nexts.clear();
      for (int leaf : leaves) {
        for (int next : adjlists[leaf]) {
          if (visited.count(next) > 0) {
            continue;
          }
          adjlists[next].erase(leaf);
          if (adjlists[next].size() <= 1) {
            nexts.push_back(next);
            visited.insert(next);
          }
        }
      }
      swap(leaves, nexts);
    }
    return leaves;
  }
};
