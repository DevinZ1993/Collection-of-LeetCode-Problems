class Solution {
 public:
  int minimumSemesters(int n, vector<vector<int>>& relations) {
    unordered_map<int, vector<int>> adjLists(n);
    for (const vector<int>& relation : relations) {
      adjLists[relation[0] - 1].push_back(relation[1] - 1);
    }
    vector<int> states(n);
    vector<int> order;
    order.reserve(n);
    vector<int> stk;
    for (int start_index = 0; start_index < n; ++start_index) {
      if (states[start_index] > 0) {
        continue;
      }
      stk.push_back(start_index);
      while (!stk.empty()) {
        const int index = stk.back();
        stk.pop_back();
        if (states[index] == 1) {
          order.push_back(index);
          states[index] = 2;
          continue;
        }
        if (states[index] == 2) {
          continue;
        }
        states[index] = 1;
        stk.emplace_back(index);
        for (int next : adjLists[index]) {
          if (states[next] == 1) {
            return -1;
          }
          if (states[next] == 0) {
            stk.emplace_back(next);
          }
        }
      }
    }
    vector<int> dists(n);
    for (auto it = order.rbegin(); it != order.rend(); ++it) {
      const int index = *it;
      for (int next : adjLists[index]) {
        dists[next] = max(dists[next], dists[index] + 1);
      }
    }
    return *max_element(dists.begin(), dists.end()) + 1;
  }
};
