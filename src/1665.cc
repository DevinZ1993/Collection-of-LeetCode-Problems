class Solution {
 public:
  int minimumEffort(vector<vector<int>> &tasks) {
    sort(tasks.begin(), tasks.end(), [](const auto &lhs, const auto &rhs) {
      return lhs[1] - lhs[0] < rhs[1] - rhs[0];
    });
    int result = 0;
    for (const auto &task : tasks) {
      result = max(task[1], task[0] + result);
    }
    return result;
  }
};
