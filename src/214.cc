class Solution {
 public:
  string shortestPalindrome(string s) {
    const int n = s.size();
    vector<int> kmp(n);
    for (int i = 1; i < n; ++i) {
      int j = kmp[i - 1];
      while (j > 0 && s[j] != s[i]) {
        j = kmp[j - 1];
      }
      if (s[j] == s[i]) {
        ++j;
      }
      kmp[i] = j;
    }

    int state = 0;
    for (int i = n - 1; i >= 0; --i) {
      while (state > 0 && s[state] != s[i]) {
        state = kmp[state - 1];
      }
      if (s[state] == s[i]) {
        ++state;
      }
    }

    string result;
    result.reserve(n * 2 - state);
    for (int i = n - 1; i >= state; --i) {
      result.push_back(s[i]);
    }
    result.append(s);
    return result;
  }
};
