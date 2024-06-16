class Solution {
 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    const int n = tasks.size();
    priority_queue<pair<int, int>> waiting_q;
    for (int i = 0; i < n; ++i) {
      waiting_q.emplace(-tasks[i][0], i);
    }
    vector<int> results;
    results.reserve(n);
    priority_queue<pair<int, int>> ready_q;
    long long time = 0;
    for (; !waiting_q.empty() || !ready_q.empty();) {
      if (ready_q.empty()) {
        time = max<long long>(time, -waiting_q.top().first);
      }
      while (!waiting_q.empty() && -waiting_q.top().first <= time) {
        const int index = waiting_q.top().second;
        waiting_q.pop();
        ready_q.emplace(-tasks[index][1], -index);
      }
      const int index = -ready_q.top().second;
      results.push_back(index);
      ready_q.pop();
      time += tasks[index][1];
    }
    return results;
  }
};
