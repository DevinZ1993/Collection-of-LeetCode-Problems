class Solution {
 public:
  bool canBeValid(string s, string locked) {
    const int n = s.size();
    deque<int> q;
    int state = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        ++state;
        continue;
      }
      if (locked[i] == '0') {
        q.push_back(i);
      }
      if (state == 0) {
        if (q.empty()) {
          return false;
        }
        const int j = q.front();
        q.pop_front();
        s[j] = '(';
        locked[j] = true;
        ++state;
      } else {
        --state;
      }
    }
    q.clear();
    state = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == ')') {
        ++state;
        continue;
      }
      if (locked[i] == '0') {
        q.push_back(i);
      }
      if (state == 0) {
        if (q.empty()) {
          return false;
        }
        const int j = q.front();
        q.pop_front();
        s[j] = ')';
        locked[j] = true;
        ++state;
      } else {
        --state;
      }
    }
    return state == 0;
  }
};
