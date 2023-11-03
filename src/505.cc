class Solution {
 public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
                       vector<int>& destination) {
    if (start == destination) {
      return 0;
    }

    constexpr array<pair<int, int>, 4> kDirs = {
        {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    const int m = maze.size();
    const int n = maze[0].size();
    vector<vector<array<int, 4>>> dist_to_walls(m, vector<array<int, 4>>(n));
    for (int j = 0; j < n; ++j) {
      int last_wall = -1;
      for (int i = 0; i < m; ++i) {
        if (maze[i][j] == 0) {
          dist_to_walls[i][j][0] = i - last_wall;
        } else {
          last_wall = i;
        }
      }
      last_wall = m;
      for (int i = m - 1; i >= 0; --i) {
        if (maze[i][j] == 0) {
          dist_to_walls[i][j][1] = last_wall - i;
        } else {
          last_wall = i;
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      int last_wall = -1;
      for (int j = 0; j < n; ++j) {
        if (maze[i][j] == 0) {
          dist_to_walls[i][j][2] = j - last_wall;
        } else {
          last_wall = j;
        }
      }
      last_wall = n;
      for (int j = n - 1; j >= 0; --j) {
        if (maze[i][j] == 0) {
          dist_to_walls[i][j][3] = last_wall - j;
        } else {
          last_wall = j;
        }
      }
    }

    vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
    dists[start[0]][start[1]] = 0;
    priority_queue<tuple<int, int, int>> q;
    q.emplace(0, start[0], start[1]);
    while (!q.empty()) {
      auto [neg_dist, i, j] = q.top();
      q.pop();
      if (-neg_dist > dists[i][j]) {
        continue;
      }
      if (i == destination[0] && j == destination[1]) {
        return dists[i][j];
      }
      for (int dir_idx = 0; dir_idx < kDirs.size(); ++dir_idx) {
        const int delta_dist = dist_to_walls[i][j][dir_idx] - 1;
        const int next_i = i + kDirs[dir_idx].first * delta_dist;
        const int next_j = j + kDirs[dir_idx].second * delta_dist;
        if (dists[next_i][next_j] > dists[i][j] + delta_dist) {
          dists[next_i][next_j] = dists[i][j] + delta_dist;
          q.emplace(-dists[next_i][next_j], next_i, next_j);
        }
      }
    }
    return -1;
  }
};
