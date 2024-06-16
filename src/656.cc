class Solution {
 public:
  vector<int> cheapestJump(vector<int>& coins, int maxJump) {
    const int n = coins.size();
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = coins[n - 1] < 0 ? INT_MAX : coins[n - 1];
    deque<int> q;
    if (dp[n - 1] < INT_MAX) {
      q.push_back(n - 1);
    }
    vector<int> nexts(n, n);
    for (int i = n - 2; i >= 0; --i) {
      if (!q.empty() && q.front() > i + maxJump) {
        q.pop_front();
      }
      if (coins[i] >= 0 && !q.empty()) {
        dp[i] = dp[q.front()] + coins[i];
        nexts[i] = q.front();
      }
      if (dp[i] == INT_MAX) {
        continue;
      }
      while (!q.empty() && dp[q.back()] >= dp[i]) {
        q.pop_back();
      }
      q.push_back(i);
    }
    if (dp[0] == INT_MAX) {
      return {};
    }
    vector<int> results;
    results.reserve(dp[0]);
    for (int i = 0; i < n; i = nexts[i]) {
      results.push_back(i + 1);
    }
    return results;
  }
};
