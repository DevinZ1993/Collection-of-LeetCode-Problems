class Solution {
 public:
  vector<int> countPairs(int n, vector<vector<int>> &edges,
                         vector<int> &queries) {
    vector<int> points(n);
    vector<unordered_map<int, int>> adj_lists(n);
    for (const auto &edge : edges) {
      const int i = min(edge[0], edge[1]) - 1;
      const int j = max(edge[0], edge[1]) - 1;
      ++points[i];
      ++points[j];
      ++adj_lists[i][j];
    }

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(),
         [&points](int i, int j) { return points[i] < points[j]; });

    vector<int> results;
    results.reserve(queries.size());
    for (int query : queries) {
      int &result = results.emplace_back();
      for (int i = 0, j = n - 1; i < n; ++i) {
        while (j > i && points[indices[i]] + points[indices[j]] > query) {
          --j;
        }
        result += n - max(i, j) - 1;
      }
      for (int i = 0; i < n; ++i) {
        for (const auto &[j, count] : adj_lists[i]) {
          if (points[i] + points[j] > query &&
              points[i] + points[j] - count <= query) {
            --result;
          }
        }
      }
    }
    return results;
  }
};
