class Solution {
 public:
  int minCost(int maxTime, vector<vector<int>>& edges,
              vector<int>& passingFees) {
    const int n = passingFees.size();
    vector<unordered_map<int, int>> prevs(n);
    const auto update_edge = [&prevs](int i, int j, int t) {
      if (auto it = prevs[i].find(j); it != prevs[i].end()) {
        it->second = min(it->second, t);
      } else {
        prevs[i].emplace(j, t);
      }
    };
    for (const auto& edge : edges) {
      update_edge(edge[0], edge[1], edge[2]);
      update_edge(edge[1], edge[0], edge[2]);
    }
    vector<vector<int>> dp(maxTime + 1, vector<int>(n, INT_MAX));
    dp[0][0] = passingFees[0];
    for (int t = 1; t <= maxTime; ++t) {
      dp[t] = dp[t - 1];
      for (int index = 0; index < n; ++index) {
        for (const auto& [prev_index, dt] : prevs[index]) {
          if (t >= dt && dp[t - dt][prev_index] < INT_MAX) {
            dp[t][index] =
                min(dp[t][index], dp[t - dt][prev_index] + passingFees[index]);
          }
        }
      }
    }
    return dp[maxTime][n - 1] < INT_MAX ? dp[maxTime][n - 1] : -1;
  }
};
