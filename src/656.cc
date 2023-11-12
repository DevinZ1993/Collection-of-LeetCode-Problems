class Solution {
 public:
  vector<int> cheapestJump(vector<int>& coins, int maxJump) {
    if (coins.back() < 0) {
      return {};
    }
    const int n = coins.size();
    vector<pair<int, int>> dp(n, {INT_MAX, -1});
    dp[n - 1].first = coins[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      if (coins[i] < 0) {
        continue;
      }
      for (int j = i + 1; j <= i + maxJump && j < n; ++j) {
        if (dp[j].first < INT_MAX && dp[i].first > dp[j].first + coins[i]) {
          dp[i].first = dp[j].first + coins[i];
          dp[i].second = j;
        }
      }
    }
    if (dp[0].first == INT_MAX) {
      return {};
    }
    vector<int> results;
    for (int i = 0; i >= 0; i = dp[i].second) {
      results.push_back(i + 1);
    }
    return results;
  }
};
