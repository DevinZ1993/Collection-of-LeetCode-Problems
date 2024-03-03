class Solution {
 public:
  vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<int> roots(m * n, -1);
    unordered_map<int, int> indices;
    for (int i = 0; i < m; ++i) {
      indices.clear();
      for (int j = 0; j < n; ++j) {
        auto it = indices.find(matrix[i][j]);
        if (it == indices.end()) {
          indices.emplace(matrix[i][j], i * n + j);
        } else {
          unionByRank(roots, i * n + j, it->second);
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      indices.clear();
      for (int i = 0; i < m; ++i) {
        auto it = indices.find(matrix[i][j]);
        if (it == indices.end()) {
          indices.emplace(matrix[i][j], i * n + j);
        } else {
          unionByRank(roots, i * n + j, it->second);
        }
      }
    }
    vector<vector<int>> adjLists(m * n);
    vector<pair<int, int>> value_index_pairs;
    value_index_pairs.reserve(max(m, n));
    for (int i = 0; i < m; ++i) {
      value_index_pairs.clear();
      for (int j = 0; j < n; ++j) {
        value_index_pairs.emplace_back(matrix[i][j], getRoot(roots, i * n + j));
      }
      sort(value_index_pairs.begin(), value_index_pairs.end());
      value_index_pairs.erase(
          unique(value_index_pairs.begin(), value_index_pairs.end()),
          value_index_pairs.end());
      for (int j = 1; j < value_index_pairs.size(); ++j) {
        adjLists[value_index_pairs[j - 1].second].push_back(
            value_index_pairs[j].second);
      }
    }
    for (int j = 0; j < n; ++j) {
      value_index_pairs.clear();
      for (int i = 0; i < m; ++i) {
        value_index_pairs.emplace_back(matrix[i][j], getRoot(roots, i * n + j));
      }
      sort(value_index_pairs.begin(), value_index_pairs.end());
      value_index_pairs.erase(
          unique(value_index_pairs.begin(), value_index_pairs.end()),
          value_index_pairs.end());
      for (int i = 1; i < value_index_pairs.size(); ++i) {
        adjLists[value_index_pairs[i - 1].second].push_back(
            value_index_pairs[i].second);
      }
    }
    vector<int> order;
    order.reserve(m * n);
    vector<int> states(m * n);
    vector<int> stk;
    for (int start_index = 0; start_index < m * n; ++start_index) {
      if (roots[start_index] >= 0 || states[start_index] > 0) {
        continue;
      }
      stk.push_back(start_index);
      while (!stk.empty()) {
        const int index = stk.back();
        stk.pop_back();
        if (states[index] == 2) {
          continue;
        }
        if (states[index] == 1) {
          ++states[index];
          order.push_back(index);
          continue;
        }
        ++states[index];
        stk.push_back(index);
        for (int next : adjLists[index]) {
          if (states[next] == 0) {
            stk.push_back(next);
          }
        }
      }
    }
    vector<vector<int>> results(m, vector<int>(n, 1));
    while (!order.empty()) {
      const int index = order.back();
      order.pop_back();
      for (int next : adjLists[index]) {
        auto &next_result = results[next / n][next % n];
        next_result = max(next_result, results[index / n][index % n] + 1);
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        const int index = i * n + j;
        if (roots[index] >= 0) {
          results[i][j] = results[roots[index] / n][roots[index] % n];
        }
      }
    }
    return results;
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
