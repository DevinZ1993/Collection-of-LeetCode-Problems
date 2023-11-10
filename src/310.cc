class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
      return {0};
    }
    vector<unordered_set<int>> adjLists(n);
    for (const auto& edge : edges) {
      adjLists[edge[0]].insert(edge[1]);
      adjLists[edge[1]].insert(edge[0]);
    }
    vector<int> leaves;
    int cnt = n;
    for (int i = 0; i < n; ++i) {
      if (adjLists[i].size() == 1) {
        leaves.push_back(i);
        --cnt;
      }
    }
    vector<int> tmp;
    while (cnt > 0) {
      tmp.clear();
      for (int leaf : leaves) {
        for (int next : adjLists[leaf]) {
          adjLists[next].erase(leaf);
          if (adjLists[next].size() == 1) {
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
