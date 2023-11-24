class Solution {
 public:
  int maxEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end());
    int result = 0;
    priority_queue<int> q;
    for (int i = 0, day = INT_MIN; i < events.size() || !q.empty(); ++day) {
      if (q.empty()) {
        day = events[i][0];
      }
      for (; i < events.size(); ++i) {
        if (events[i][0] > day) {
          break;
        }
        q.push(-events[i][1]);
      }
      if (!q.empty()) {
        q.pop();
        ++result;
      }
      while (!q.empty() && -q.top() == day) {
        q.pop();
      }
    }
    return result;
  }
};
