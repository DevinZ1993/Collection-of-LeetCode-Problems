class Solution {
 public:
  long long minCost(vector<int>& basket1, vector<int>& basket2) {
    unordered_map<int, int> cnts;
    for (int num : basket1) {
      ++cnts[num];
    }
    for (int num : basket2) {
      --cnts[num];
    }
    int min_val = INT_MAX;
    priority_queue<int> q;
    for (auto [val, cnt] : cnts) {
      if (cnt % 2 != 0) {
        return -1;
      }
      min_val = min(min_val, val);
      cnt = abs(cnt);
      while (cnt > 0) {
        q.push(val);
        cnt -= 2;
      }
    }
    const int n = q.size() / 2;
    while (q.size() > n) {
      q.pop();
    }
    long long result = 0;
    while (!q.empty()) {
      result += min(2 * min_val, q.top());
      q.pop();
    }
    return result;
  }
};
