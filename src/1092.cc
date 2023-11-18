class Solution {
 public:
  string shortestCommonSupersequence(string str1, string str2) {
    const int m = str1.size();
    const int n = str2.size();
    vector<vector<tuple<int, int, int>>> dp(
        m + 1, vector<tuple<int, int, int>>(n + 1));
    dp[m][n] = {0, m, n};
    for (int j = n - 1; j >= 0; --j) {
      dp[m][j] = {n - j, m, j + 1};
    }
    for (int i = m - 1; i >= 0; --i) {
      dp[i][n] = {m - i, i + 1, n};
      for (int j = n - 1; j >= 0; --j) {
        if (get<0>(dp[i + 1][j]) < get<0>(dp[i][j + 1])) {
          dp[i][j] = {1 + get<0>(dp[i + 1][j]), i + 1, j};
        } else {
          dp[i][j] = {1 + get<0>(dp[i][j + 1]), i, j + 1};
        }
        if (str1[i] == str2[j] &&
            1 + get<0>(dp[i + 1][j + 1]) < get<0>(dp[i][j])) {
          dp[i][j] = {1 + get<0>(dp[i + 1][j + 1]), i + 1, j + 1};
        }
      }
    }
    string result;
    result.reserve(get<0>(dp[0][0]));
    for (int i = 0, j = 0; i < m || j < n;) {
      auto [_, next_i, next_j] = dp[i][j];
      if (i < next_i) {
        result.push_back(str1[i]);
      } else {
        result.push_back(str2[j]);
      }
      i = next_i;
      j = next_j;
    }
    return result;
  }
};
