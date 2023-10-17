class Solution {
 public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int start_index = -1;
    int end_index = -1;
    int target = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          start_index = i * n + j;
          target |= (1 << start_index);
        } else if (grid[i][j] == 2) {
          end_index = i * n + j;
        } else if (grid[i][j] == 0) {
          target |= (1 << (i * n + j));
        }
      }
    }

    vector<unordered_map<int, int>> memo(m * n);
    deque<pair<int, int>> q;
    q.emplace_back(start_index, 1 << start_index);
    memo[start_index].emplace(1 << start_index, 1);
    while (!q.empty()) {
      const int state = q.front().second;
      const int i = q.front().first / n;
      const int j = q.front().first % n;
      q.pop_front();
      if (grid[i][j] == 2) {
        continue;
      }
      const int cnt = memo[i * n + j].at(state);
      for (const auto [next_i, next_j] : vector<pair<int, int>>{
               {i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}}) {
        const int next_index = next_i * n + next_j;
        if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n ||
            grid[next_i][next_j] < 0 || (state & (1 << next_index)) != 0) {
          continue;
        }
        if (state != target && grid[next_i][next_j] == 2) {
          continue;
        }
        const int next_state = (state | (1 << next_index));
        auto it = memo[next_index].find(next_state);
        if (it == memo[next_index].end()) {
          q.emplace_back(next_index, next_state);
          memo[next_index].emplace(next_state, cnt);
        } else {
          it->second += cnt;
        }
      }
    }
    int result = 0;
    for (const auto& [_, cnt] : memo[end_index]) {
      result += cnt;
    }
    return result;
  }
};
