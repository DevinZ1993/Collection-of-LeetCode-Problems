class Solution {
 public:
  int getLengthOfOptimalCompression(string s, int k) {
    const int n = s.size();
    const int m = n - k;
    if (m == 0) {
      return 0;
    }
    constexpr auto length = [](int cnt) {
      if (cnt == 1) {
        return 1;
      } else if (cnt < 10) {
        return 2;
      } else if (cnt < 100) {
        return 3;
      }
      return 4;
    };
    vector<vector<vector<int>>> dp(
        m, vector<vector<int>>(26, vector<int>(m, INT_MAX)));
    vector<vector<vector<int>>> last_dp(
        m, vector<vector<int>>(26, vector<int>(m, INT_MAX)));
    for (char ch : s) {
      last_dp = dp;
      for (int i = 0; i + 1 < m; ++i) {
        for (int j = 0; j < 26; ++j) {
          for (int kk = 0; kk + 1 < m; ++kk) {
            if (last_dp[i][j][kk] == INT_MAX) {
              continue;
            }
            if (ch == 'a' + j) {
              dp[i + 1][j][kk + 1] =
                  min(dp[i + 1][j][kk + 1],
                      last_dp[i][j][kk] - length(kk + 1) + length(kk + 2));
            } else {
              dp[i + 1][ch - 'a'][0] =
                  min(dp[i + 1][ch - 'a'][0], last_dp[i][j][kk] + 1);
            }
          }
        }
      }
      dp[0][ch - 'a'][0] = 1;
    }

    int result = INT_MAX;
    for (int j = 0; j < 26; ++j) {
      for (int kk = 0; kk < m; ++kk) {
        result = min(result, dp[m - 1][j][kk]);
      }
    }
    return result;
  }
};
