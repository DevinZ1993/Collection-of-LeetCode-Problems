class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    constexpr array<pair<int, int>, 4> kDirs = {
        {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    vector<vector<int>> states(m, vector<int>(n));
    vector<pair<int, int>> stk;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (states[i][j] > 0) {
          continue;
        }
        stk.emplace_back(i, j);
        while (!stk.empty()) {
          const auto [ii, jj] = stk.back();
          stk.pop_back();
          if (states[ii][jj] == 2) {
            continue;
          }
          const int state = states[ii][jj];
          ++states[ii][jj];
          if (state == 0) {
            stk.emplace_back(ii, jj);
          }
          dp[ii][jj] = 1;
          for (const auto [di, dj] : kDirs) {
            const int next_i = ii + di;
            const int next_j = jj + dj;
            if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n ||
                matrix[next_i][next_j] <= matrix[ii][jj]) {
              continue;
            }
            if (state == 0) {
              if (states[next_i][next_j] == 0) {
                stk.emplace_back(next_i, next_j);
              }
            } else {
              dp[ii][jj] = max(dp[ii][jj], 1 + dp[next_i][next_j]);
            }
          }
        }
      }
    }
    int result = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        result = max(result, dp[i][j]);
      }
    }
    return result;
  }
};
