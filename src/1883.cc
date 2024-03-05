class Solution {
 public:
  int minSkips(vector<int>& dist, int speed, int hoursBefore) {
    const int n = dist.size();
    vector<long long> dp(n + 1, LLONG_MAX);
    vector<long long> last_dp(n + 1, LLONG_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
      swap(dp, last_dp);
      dp[i + 1] = last_dp[i] + dist[i];
      for (int j = i; j >= 0; --j) {
        dp[j] = (last_dp[j] + speed - 1) / speed * speed + dist[i];
        if (j > 0) {
          dp[j] = min(dp[j], last_dp[j - 1] + dist[i]);
        }
      }
    }
    auto it = find_if(dp.begin(), dp.end(), [hoursBefore, speed](long long s) {
      return s <= 1LL * hoursBefore * speed;
    });
    if (it == dp.end()) {
      return -1;
    }
    return distance(dp.begin(), it);
  }
};
