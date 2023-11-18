class Solution {
 public:
  int removeStones(vector<vector<int>> &stones) {
    const int n = stones.size();
    vector<int> roots(n, -1);
    unordered_map<int, int> rows;
    unordered_map<int, int> cols;
    for (int index = 0; index < n; ++index) {
      auto row_it = rows.find(stones[index][0]);
      if (row_it == rows.end()) {
        rows.emplace(stones[index][0], index);
      } else {
        unionByRank(roots, row_it->second, index);
      }
      auto col_it = cols.find(stones[index][1]);
      if (col_it == cols.end()) {
        cols.emplace(stones[index][1], index);
      } else {
        unionByRank(roots, col_it->second, index);
      }
    }
    int result = n;
    for (int i = 0; i < n; ++i) {
      if (roots[i] < 0) {
        --result;
      }
    }
    return result;
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
