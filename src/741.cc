class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    const int n = grid.size();
    vector<int> prev_is;
    prev_is.reserve(2);
    vector<int> prev_js;
    prev_js.reserve(2);
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n)));
    dp[0][0][0] = grid[0][0];
    for (int k = 1; k <= 2 * n - 2; ++k) {
      for (auto& row : dp[k % 2]) {
        fill(row.begin(), row.end(), INT_MIN);
      }
      for (int i = max(0, k - n + 1); i < n && i <= k; ++i) {
        if (grid[i][k - i] < 0) {
          continue;
        }
        prev_is.clear();
        if (k - 1 - i >= 0) {
          prev_is.push_back(i);
        }
        if (i > 0) {
          prev_is.push_back(i - 1);
        }
        for (int j = i; j < n && j <= k; ++j) {
          if (grid[j][k - j] < 0) {
            continue;
          }
          prev_js.clear();
          if (k - 1 - j >= 0) {
            prev_js.push_back(j);
          }
          if (j > 0) {
            prev_js.push_back(j - 1);
          }
          for (int prev_i : prev_is) {
            for (int prev_j : prev_js) {
              if (prev_i > prev_j || dp[1 - k % 2][prev_i][prev_j] < 0) {
                continue;
              }
              dp[k % 2][i][j] =
                  max(dp[k % 2][i][j], grid[i][k - i] +
                                           (i == j ? 0 : grid[j][k - j]) +
                                           dp[1 - k % 2][prev_i][prev_j]);
            }
          }
        }
      }
    }
    return max(0, dp[0][n - 1][n - 1]);
  }
};
