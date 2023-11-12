class Solution {
 public:
  bool canCross(vector<int>& stones) {
    const int n = stones.size();
    unordered_map<int, int> indices;
    for (int i = 0; i < n; ++i) {
      indices[stones[i]] = i;
    }
    vector<unordered_set<int>> dp(n);
    dp[0].insert(1);
    for (int i = 0; i < n; ++i) {
      for (int step : dp[i]) {
        auto it = indices.find(stones[i] + step);
        if (it == indices.end()) {
          continue;
        }
        auto& next_state = dp[it->second];
        next_state.insert(step - 1);
        next_state.insert(step);
        next_state.insert(step + 1);
      }
    }
    return !dp.back().empty();
  }
};
