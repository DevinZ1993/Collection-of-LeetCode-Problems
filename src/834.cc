class Solution {
 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adjLists(n);
    for (const auto& edge : edges) {
      adjLists[edge[0]].push_back(edge[1]);
      adjLists[edge[1]].push_back(edge[0]);
    }

    vector<int> sums(n);
    vector<int> counts(n, 1);
    vector<int> parents(n, -1);
    vector<pair<int, int>> stk;
    stk.emplace_back(0, 0);
    while (!stk.empty()) {
      const auto [index, state] = stk.back();
      stk.pop_back();
      if (state == 0) {
        stk.emplace_back(index, 1);
        for (int next : adjLists[index]) {
          if (next != parents[index]) {
            parents[next] = index;
            stk.emplace_back(next, 0);
          }
        }
      } else {
        for (int next : adjLists[index]) {
          if (parents[next] == index) {
            counts[index] += counts[next];
            sums[index] += counts[next] + sums[next];
          }
        }
      }
    }
    stk.emplace_back(0, 0);
    while (!stk.empty()) {
      const int index = stk.back().first;
      stk.pop_back();
      if (parents[index] >= 0) {
        const int parent = parents[index];
        const int parent_count = n - counts[index];
        const int parent_sum = sums[parent] - counts[index] - sums[index];
        sums[index] += parent_count + parent_sum;
      }
      for (int next : adjLists[index]) {
        if (parents[next] == index) {
          stk.emplace_back(next, 0);
        }
      }
    }
    return sums;
  }
};
