class Solution {
 public:
  int maximumInvitations(vector<vector<int>> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<unordered_set<int>> adjLists(m + n + 2);
    for (int i = 0; i < m; ++i) {
      adjLists[0].insert(i + 2);
    }
    for (int j = 0; j < n; ++j) {
      adjLists[j + m + 2].insert(1);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          adjLists[i + 2].insert(j + m + 2);
        }
      }
    }
    return maxFlow(adjLists, 0, 1);
  }

 private:
  int maxFlow(vector<unordered_set<int>> &adjLists, int source, int target) {
    vector<int> prevs(adjLists.size());
    int result = 0;
    while (true) {
      const int flow = bfs(adjLists, source, target, prevs);
      if (flow == 0) {
        break;
      }
      result += flow;
    }
    return result;
  }
  int bfs(vector<unordered_set<int>> &adjLists, int source, int target,
          vector<int> &prevs) {
    fill(prevs.begin(), prevs.end(), -1);
    deque<int> q = {source};
    prevs[source] = source;
    while (!q.empty() && prevs[target] < 0) {
      const int index = q.front();
      q.pop_front();
      for (int next : adjLists[index]) {
        if (prevs[next] < 0) {
          prevs[next] = index;
          q.push_back(next);
        }
      }
    }
    if (prevs[target] < 0) {
      return 0;
    }
    for (int i = target; i != source; i = prevs[i]) {
      adjLists[prevs[i]].erase(i);
      adjLists[i].insert(prevs[i]);
    }
    return 1;
  }
};
