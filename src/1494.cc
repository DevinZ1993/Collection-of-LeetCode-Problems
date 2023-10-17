class Solution {
 public:
  int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
    vector<int> prevs(n);
    for (const auto& relation : relations) {
      prevs[relation[1] - 1] |= (1 << (relation[0] - 1));
    }

    vector<int> cnts(1 << n);
    for (int state = 1; state < cnts.size(); ++state) {
      cnts[state] = cnts[state & (state - 1)] + 1;
    }

    vector<int> dists(1 << n, INT_MAX);
    dists[0] = 0;
    deque<int> q = {0};
    while (!q.empty()) {
      const int state = q.front();
      q.pop_front();
      int nexts = 0;
      for (int i = 0; i < n; ++i) {
        if ((state & (1 << i)) == 0 && (state & prevs[i]) == prevs[i]) {
          nexts |= (1 << i);
        }
      }
      for (int sub = nexts; sub > 0; sub = (nexts & (sub - 1))) {
        if (cnts[sub] <= k && dists[state | sub] > dists[state] + 1) {
          dists[state | sub] = dists[state] + 1;
          q.push_back(state | sub);
        }
      }
    }
    return dists.back();
  }
};
