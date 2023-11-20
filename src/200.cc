class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    constexpr array<pair<int, int>, 4> kDirs = {
        {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n));
    vector<pair<int, int>> stk;
    int result = 0;
    for (int start_i = 0; start_i < m; ++start_i) {
      for (int start_j = 0; start_j < n; ++start_j) {
        if (vis[start_i][start_j] || grid[start_i][start_j] != '1') {
          continue;
        }
        ++result;
        vis[start_i][start_j] = true;
        stk.emplace_back(start_i, start_j);
        while (!stk.empty()) {
          const auto [i, j] = stk.back();
          stk.pop_back();
          for (const auto [di, dj] : kDirs) {
            const int next_i = i + di;
            const int next_j = j + dj;
            if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n ||
                vis[next_i][next_j] || grid[next_i][next_j] != '1') {
              continue;
            }
            vis[next_i][next_j] = true;
            stk.emplace_back(next_i, next_j);
          }
        }
      }
    }
    return result;
  }
};
