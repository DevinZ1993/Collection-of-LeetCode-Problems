class Solution {
 public:
  string shortestSuperstring(vector<string>& words) {
    const int n = words.size();
    vector<vector<int>> overlaps(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) {
          overlaps[i][j] = words[i].size();
          continue;
        }
        int len = min(words[i].size(), words[j].size());
        for (; len > 0; --len) {
          if (equal(words[j].begin(), next(words[j].begin(), len),
                    prev(words[i].end(), len))) {
            break;
          }
        }
        overlaps[i][j] = len;
      }
    }
    vector<vector<pair<int, int>>> dp(1 << n,
                                      vector<pair<int, int>>(n, {INT_MAX, -1}));
    for (int state = 0; state < dp.size(); ++state) {
      for (int i = 0; i < n; ++i) {
        if ((state & (1 << i)) == 0) {
          continue;
        }
        if (state == (1 << i)) {
          dp[state][i].first = words[i].size();
          break;
        }
        const int prev = (state & ~(1 << i));
        for (int j = 0; j < n; ++j) {
          if (dp[prev][j].first == INT_MAX) {
            continue;
          }
          if (dp[prev][j].first + words[i].size() - overlaps[i][j] <
              dp[state][i].first) {
            dp[state][i].first =
                dp[prev][j].first + words[i].size() - overlaps[i][j];
            dp[state][i].second = j;
          }
        }
      }
    }
    int index = 0;
    for (int i = 1; i < n; ++i) {
      if (dp.back()[i].first < dp.back()[index].first) {
        index = i;
      }
    }
    string result;
    result.reserve(dp.back()[index].first);
    result.append(words[index]);
    int state = (1 << n) - 1;
    while (dp[state][index].second >= 0) {
      const int next = dp[state][index].second;
      result.append(words[next].substr(overlaps[index][next]));
      state &= ~(1 << index);
      index = next;
    }
    return result;
  }
};
