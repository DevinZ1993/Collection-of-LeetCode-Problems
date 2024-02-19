class Solution {
 public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
                       vector<int>& destination) {
    constexpr array<pair<int, int>, 4> kDirs = {
        {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};
    const int m = maze.size();
    const int n = maze[0].size();
    vector<vector<array<int, 4>>> dists_to_walls(m, vector<array<int, 4>>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (maze[i][j] == 1) {
          continue;
        }
        if (i == 0) {
          dists_to_walls[i][j][0] = 1;
        } else {
          dists_to_walls[i][j][0] = dists_to_walls[i - 1][j][0] + 1;
        }
        if (j == 0) {
          dists_to_walls[i][j][3] = 1;
        } else {
          dists_to_walls[i][j][3] = dists_to_walls[i][j - 1][3] + 1;
        }
      }
    }
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (maze[i][j] == 1) {
          continue;
        }
        if (i == m - 1) {
          dists_to_walls[i][j][2] = 1;
        } else {
          dists_to_walls[i][j][2] = dists_to_walls[i + 1][j][2] + 1;
        }
        if (j == n - 1) {
          dists_to_walls[i][j][1] = 1;
        } else {
          dists_to_walls[i][j][1] = dists_to_walls[i][j + 1][1] + 1;
        }
      }
    }

    vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
    dists[start[0]][start[1]] = 0;
    priority_queue<tuple<int, int, int>> q;
    q.emplace(0, start[0], start[1]);
    while (!q.empty()) {
      const auto [neg_dist, i, j] = q.top();
      q.pop();
      if (i == destination[0] && j == destination[1]) {
        return dists[i][j];
      }
      if (-neg_dist > dists[i][j]) {
        continue;
      }
      for (int k = 0; k < kDirs.size(); ++k) {
        const int dist = dists_to_walls[i][j][k] - 1;
        const int next_i = i + dist * kDirs[k].first;
        const int next_j = j + dist * kDirs[k].second;
        if (dists[next_i][next_j] > dists[i][j] + dist) {
          dists[next_i][next_j] = dists[i][j] + dist;
          q.emplace(-dists[next_i][next_j], next_i, next_j);
        }
      }
    }
    return -1;
  }
};
