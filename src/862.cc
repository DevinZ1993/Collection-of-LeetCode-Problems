class Solution {
 public:
  int shortestSubarray(vector<int>& nums, int k) {
    int result = INT_MAX;
    deque<pair<int, long long>> q;
    long long sum = 0;
    q.emplace_back(-1, 0);
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      while (!q.empty() && sum - q.front().second >= k) {
        result = min(result, i - q.front().first);
        q.pop_front();
      }
      while (!q.empty() && q.back().second >= sum) {
        q.pop_back();
      }
      q.emplace_back(i, sum);
    }
    return result == INT_MAX ? -1 : result;
  }
};
