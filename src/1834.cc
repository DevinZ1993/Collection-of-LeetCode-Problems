class Solution {
 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    const int n = tasks.size();
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&tasks](int i, int j) {
      if (tasks[i] != tasks[j]) {
        return tasks[i] < tasks[j];
      }
      return i < j;
    });
    vector<int> results;
    results.reserve(n);
    priority_queue<pair<int, int>> q;
    long long time = LLONG_MIN;
    for (int i = 0; i < n || !q.empty();) {
      if (q.empty()) {
        time = max<long long>(time, tasks[indices[i]][0]);
      }
      for (; i < n && tasks[indices[i]][0] <= time; ++i) {
        q.emplace(-tasks[indices[i]][1], -indices[i]);
      }
      results.push_back(-q.top().second);
      time -= q.top().first;
      q.pop();
    }
    return results;
  }
};
