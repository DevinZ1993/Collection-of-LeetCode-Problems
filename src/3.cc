class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    array<int, 128> cnts{};
    int result = 0;
    for (int i = 0, j = 0; j < s.size(); ++j) {
      while (cnts[s[j]] > 0) {
        --cnts[s[i]];
        ++i;
      }
      ++cnts[s[j]];
      result = max(result, j - i + 1);
    }
    return result;
  }
};
