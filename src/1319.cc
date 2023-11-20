class Solution {
 public:
  int makeConnected(int n, vector<vector<int>> &connections) {
    if (connections.size() < n - 1) {
      return -1;
    }
    vector<int> roots(n, -1);
    for (const auto &connection : connections) {
      unionByRank(roots, connection[0], connection[1]);
    }
    int groups = 0;
    for (int i = 0; i < n; ++i) {
      if (roots[i] < 0) {
        ++groups;
      }
    }
    return groups - 1;
  }

 private:
  void unionByRank(vector<int> &roots, int i, int j) {
    i = getRoot(roots, i);
    j = getRoot(roots, j);
    if (i == j) {
      return;
    }
    if (roots[i] > roots[j]) {
      swap(i, j);
    }
    roots[i] += roots[j];
    roots[j] = i;
  }

  int getRoot(vector<int> &roots, int i) {
    if (roots[i] < 0) {
      return i;
    }
    return roots[i] = getRoot(roots, roots[i]);
  }
};
