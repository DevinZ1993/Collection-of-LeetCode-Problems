class Solution {
 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj_lists(n);
    for (const auto& edge : edges) {
      adj_lists[edge[0]].push_back(edge[1]);
      adj_lists[edge[1]].push_back(edge[0]);
    }

    vector<int> dist_sums(n);
    vector<int> counts(n, 1);
    vector<tuple<int, int, int>> stk;
    stk.emplace_back(0, -1, 0);
    while (!stk.empty()) {
      const auto [index, prev_index, state] = stk.back();
      stk.pop_back();
      if (state == 0) {
        stk.emplace_back(index, prev_index, 1);
        for (int next_index : adj_lists[index]) {
          if (next_index == prev_index) {
            continue;
          }
          stk.emplace_back(next_index, index, 0);
        }
        continue;
      }
      for (int next_index : adj_lists[index]) {
        if (next_index == prev_index) {
          continue;
        }
        counts[index] += counts[next_index];
        dist_sums[index] += dist_sums[next_index] + counts[next_index];
      }
    }
    stk.emplace_back(0, -1, 0);
    while (!stk.empty()) {
      const auto [index, prev_index, _] = stk.back();
      stk.pop_back();
      for (int next_index : adj_lists[index]) {
        if (next_index == prev_index) {
          continue;
        }
        dist_sums[next_index] += dist_sums[index] -
                                 (dist_sums[next_index] + counts[next_index]) +
                                 (n - counts[next_index]);
        stk.emplace_back(next_index, index, 0);
      }
    }
    return dist_sums;
  }
};
