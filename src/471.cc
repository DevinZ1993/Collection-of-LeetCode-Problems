class Solution {
 public:
  struct State {
    int val = INT_MAX;
    int count = 0;
    int mid_index = -1;
  };

  string encode(string s) {
    const int n = s.size();
    vector<vector<State>> dp(n);
    for (int len = 1; len <= n; ++len) {
      dp[len - 1].resize(n - len + 1);
      for (int i = 0; i + len <= n; ++i) {
        if (len == 1) {
          dp[len - 1][i].val = 1;
          dp[len - 1][i].count = 1;
          continue;
        }
        for (int j = i + 1; j < i + len; ++j) {
          if (dp[j - i - 1][i].val + dp[i + len - j - 1][j].val <
              dp[len - 1][i].val) {
            dp[len - 1][i].val =
                dp[j - i - 1][i].val + dp[i + len - j - 1][j].val;
            dp[len - 1][i].mid_index = j;
          }
        }
        for (int sub = 1; sub * 2 <= len; ++sub) {
          if (len % sub != 0) {
            continue;
          }
          bool success = true;
          for (int j = i + sub; j < i + len; ++j) {
            if (s[j] != s[j - sub]) {
              success = false;
              break;
            }
          }
          if (!success) {
            continue;
          }
          int val = dp[sub - 1][i].val + 2 + to_string(len / sub).size();
          if (val < dp[len - 1][i].val) {
            dp[len - 1][i].val = val;
            dp[len - 1][i].mid_index = -1;
            dp[len - 1][i].count = len / sub;
          }
        }
      }
    }
    return createString(s, dp, 0, n);
  }

 private:
  string createString(const string &s, const vector<vector<State>> &dp,
                      int index, int len) {
    if (dp[len - 1][index].val == len) {
      return s.substr(index, len);
    }
    const int mid_index = dp[len - 1][index].mid_index;
    if (mid_index >= 0) {
      string result = createString(s, dp, index, mid_index - index);
      result.append(createString(s, dp, mid_index, index + len - mid_index));
      return result;
    }
    string result = to_string(dp[len - 1][index].count);
    result.push_back('[');
    result.append(createString(s, dp, index, len / dp[len - 1][index].count));
    result.push_back(']');
    return result;
  }
};
