class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    const int m = dungeon.size();
    const int n = dungeon[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[m - 1][n - 1] = 1 + max(0, -dungeon[m - 1][n - 1]);
    for (int j = n - 2; j >= 0; --j) {
      dp[m - 1][j] = max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
    }
    for (int i = m - 2; i >= 0; --i) {
      dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
      for (int j = n - 2; j >= 0; --j) {
        dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
      }
    }
    return dp[0][0];
  }
};
