class Solution {
 public:
  int scheduleCourse(vector<vector<int>> &courses) {
    sort(courses.begin(), courses.end(),
         [](const auto &a, const auto &b) { return a[1] < b[1]; });
    priority_queue<int> q;
    int sum = 0;
    for (const auto &course : courses) {
      sum += course[0];
      q.push(course[0]);
      if (sum > course[1]) {
        sum -= q.top();
        q.pop();
      }
    }
    return q.size();
  }
};
