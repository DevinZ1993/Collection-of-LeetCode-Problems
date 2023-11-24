class Solution {
 public:
  int maxSizeSlices(vector<int>& slices) {
    const int n = slices.size() / 3;
    return max(solve(slices, 1, slices.size() - 1, n),
               slices[0] + solve(slices, 2, slices.size() - 2, n - 1));
  }

 private:
  int solve(const vector<int>& slices, int min_index, int max_index,
            int k) const {
    vector<vector<int>> dp(3, vector<int>(k + 1, INT_MIN));
    dp[0][0] = dp[1][0] = dp[2][0] = 0;
    for (int i = min_index; i <= max_index; ++i) {
      for (int j = 1; j <= i - min_index + 1 && j <= k; ++j) {
        dp[i % 3][j] =
            max(dp[(i + 2) % 3][j], dp[(i + 1) % 3][j - 1] + slices[i]);
      }
    }
    return dp[max_index % 3][k];
  }
};
