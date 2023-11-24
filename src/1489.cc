class Solution {
 public:
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(
      int n, vector<vector<int>> &edges) {
    const int cost = calcMst(n, edges, -1, -1);
    vector<vector<int>> results(2);
    for (int i = 0; i < edges.size(); ++i) {
      if (calcMst(n, edges, -1, i) > cost) {
        results[0].push_back(i);
      } else if (calcMst(n, edges, i, -1) == cost) {
        results[1].push_back(i);
      }
    }
    return results;
  }

 private:
  int calcMst(const int n, const vector<vector<int>> &edges, const int include,
              const int exclude) {
    vector<int> roots(n, -1);
    priority_queue<pair<int, int>> q;
    int cost = 0;
    int count = 0;
    for (int i = 0; i < edges.size(); ++i) {
      if (i == exclude) {
        continue;
      }
      if (i == include) {
        cost += edges[i][2];
        ++count;
        unionByRank(roots, edges[i][0], edges[i][1]);
      } else {
        q.emplace(-edges[i][2], i);
      }
    }
    while (count < n - 1) {
      if (q.empty()) {
        return INT_MAX;
      }
      const int index = q.top().second;
      q.pop();
      if (getRoot(roots, edges[index][0]) == getRoot(roots, edges[index][1])) {
        continue;
      }
      cost += edges[index][2];
      ++count;
      unionByRank(roots, edges[index][0], edges[index][1]);
    }
    return cost;
  }

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
