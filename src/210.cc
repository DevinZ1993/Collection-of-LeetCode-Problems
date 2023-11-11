class Solution {
 public:
  vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj_lists(n);
    for (const auto& prerequisite : prerequisites) {
      adj_lists[prerequisite[1]].push_back(prerequisite[0]);
    }
    vector<int> states(n);
    vector<int> stk;
    vector<int> results;
    results.reserve(n);
    for (int start = 0; start < n; ++start) {
      if (states[start] > 0) {
        continue;
      }
      stk.push_back(start);
      while (!stk.empty()) {
        const int i = stk.back();
        stk.pop_back();
        if (states[i] == 1) {
          ++states[i];
          results.push_back(i);
          continue;
        }
        if (states[i] == 2) {
          continue;
        }
        ++states[i];
        stk.push_back(i);
        for (int j : adj_lists[i]) {
          if (states[j] == 0) {
            stk.push_back(j);
          } else if (states[j] == 1) {
            return {};
          }
        }
      }
    }
    reverse(results.begin(), results.end());
    return results;
  }
};
