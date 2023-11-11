class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
      return {0};
    }
    vector<unordered_set<int>> adj_lists(n);
    for (const auto& edge : edges) {
      adj_lists[edge[0]].insert(edge[1]);
      adj_lists[edge[1]].insert(edge[0]);
    }
    vector<int> leaves;
    int cnt = n;
    for (int i = 0; i < n; ++i) {
      if (adj_lists[i].size() == 1) {
        leaves.push_back(i);
        --cnt;
      }
    }
    vector<int> tmp;
    while (cnt > 0) {
      tmp.clear();
      for (int leaf : leaves) {
        for (int next : adj_lists[leaf]) {
          adj_lists[next].erase(leaf);
          if (adj_lists[next].size() == 1) {
            tmp.push_back(next);
            --cnt;
          }
        }
      }
      swap(tmp, leaves);
    }
    return leaves;
  }
};
