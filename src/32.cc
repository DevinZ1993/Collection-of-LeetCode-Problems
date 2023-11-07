class Solution {
 public:
  int longestValidParentheses(string s) {
    const int n = s.size();
    vector<int> dp(n + 1);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(' || dp[i] == i || s[i - dp[i] - 1] != '(') {
        continue;
      }
      dp[i + 1] = dp[i - dp[i] - 1] + 2 + dp[i];
    }
    return *max_element(dp.begin(), dp.end());
  }
};
