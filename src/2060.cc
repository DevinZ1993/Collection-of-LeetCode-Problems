class Solution {
 public:
  bool possiblyEquals(string s1, string s2) {
    vector<vector<unordered_map<int, bool>>> memo(
        s1.size() + 1, vector<unordered_map<int, bool>>(s2.size() + 1));
    return solve(s1, s2, 0, 0, 0, memo);
  }

 private:
  bool solve(const string &s1, const string &s2, int i, int j, int diff,
             vector<vector<unordered_map<int, bool>>> &memo) {
    if (auto it = memo[i][j].find(diff); it != memo[i][j].end()) {
      return it->second;
    }
    bool &result = memo[i][j][diff];
    while (diff < 0 && i < s1.size() && s1[i] >= 'a' && s1[i] <= 'z') {
      ++diff;
      ++i;
    }
    while (diff > 0 && j < s2.size() && s2[j] >= 'a' && s2[j] <= 'z') {
      --diff;
      ++j;
    }
    if (i == s1.size() && j == s2.size()) {
      result = diff == 0;
    } else if (diff == 0 && i < s1.size() && s1[i] >= 'a' && s1[i] <= 'z' &&
               j < s2.size() && s2[j] >= 'a' && s2[j] <= 'z') {
      result = s1[i] == s2[j] && solve(s1, s2, i + 1, j + 1, 0, memo);
    } else {
      int left = 0;
      for (int ii = i - 1; ii < static_cast<int>(s1.size()) && !result; ++ii) {
        if (ii >= i) {
          if (s1[ii] < '0' || s1[ii] > '9') {
            break;
          }
          left = 10 * left + (s1[ii] - '0');
        }
        int right = 0;
        for (int jj = ii < i ? j : j - 1; jj < static_cast<int>(s2.size());
             ++jj) {
          if (jj >= j) {
            if (s2[jj] < '0' || s2[jj] > '9') {
              break;
            }
            right = 10 * right + (s2[jj] - '0');
          }
          if (solve(s1, s2, ii + 1, jj + 1, diff + left - right, memo)) {
            result = true;
            break;
          }
        }
      }
    }
    return result;
  }
};
