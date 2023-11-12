class Solution {
 public:
  int findIntegers(int n) {
    int len = 1;
    while ((1 << len) <= n) {
      ++len;
    }

    vector<vector<int>> dp(len, vector<int>(2));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < dp.size(); ++i) {
      dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
      dp[i][1] = dp[i - 1][0];
    }

    int result = 0;
    bool exit = false;
    for (int i = len - 1; i >= 0; --i) {
      if ((n & (1 << i)) == 0) {
        continue;
      }
      result += dp[i][0];
      if ((n & (1 << (i + 1))) != 0) {
        exit = true;
        break;
      }
    }
    if (!exit) {
      ++result;
    }
    return result;
  }
};
