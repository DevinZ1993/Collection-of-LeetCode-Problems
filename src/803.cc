class Solution {
 public:
  vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    vector<bool> effects(hits.size());
    for (int i = 0; i < hits.size(); ++i) {
      if (grid[hits[i][0]][hits[i][1]] == 1) {
        effects[i] = true;
        grid[hits[i][0]][hits[i][1]] = 0;
      }
    }

    const int m = grid.size();
    const int n = grid[0].size();
    vector<int> roots(m * n + 1, -1);
    for (int j = 0; j < n; ++j) {
      if (grid[0][j] == 1) {
        union_by_rank(roots, j, m * n);
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          continue;
        }
        if (i + 1 < m && grid[i + 1][j] == 1) {
          union_by_rank(roots, i * n + j, (i + 1) * n + j);
        }
        if (j + 1 < n && grid[i][j + 1] == 1) {
          union_by_rank(roots, i * n + j, i * n + j + 1);
        }
      }
    }

    constexpr array<pair<int, int>, 4> kDirs = {
        {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};
    vector<int> results(hits.size());
    int count = -roots[get_root(roots, m * n)];
    for (int i = results.size() - 1; i >= 0; --i) {
      if (!effects[i]) {
        continue;
      }
      grid[hits[i][0]][hits[i][1]] = 1;
      if (hits[i][0] == 0) {
        union_by_rank(roots, hits[i][1], m * n);
      }
      for (const auto [di, dj] : kDirs) {
        const int next_i = hits[i][0] + di;
        const int next_j = hits[i][1] + dj;
        if (next_i >= 0 && next_i < m && next_j >= 0 && next_j < n &&
            grid[next_i][next_j] == 1) {
          union_by_rank(roots, hits[i][0] * n + hits[i][1],
                        next_i * n + next_j);
        }
      }
      const int root_index = get_root(roots, m * n);
      int new_count = -roots[root_index];
      results[i] =
          new_count - count -
          (get_root(roots, hits[i][0] * n + hits[i][1]) == root_index ? 1 : 0);
      count = new_count;
    }
    return results;
  }

 private:
  int get_root(vector<int>& roots, int i) const {
    if (roots[i] < 0) {
      return i;
    }
    roots[i] = get_root(roots, roots[i]);
    return roots[i];
  }
  void union_by_rank(vector<int>& roots, int i, int j) const {
    i = get_root(roots, i);
    j = get_root(roots, j);
    if (i == j) {
      return;
    }
    if (roots[i] > roots[j]) {
      swap(i, j);
    }
    roots[i] += roots[j];
    roots[j] = i;
  }
};
