class Solution {
 public:
  static constexpr array<char, 4> kDirNames = {{'d', 'l', 'r', 'u'}};
  static constexpr array<pair<int, int>, 4> kDirs = {
      {{1, 0}, {0, -1}, {0, 1}, {-1, 0}}};

  struct Value {
    int dist = INT_MAX;
    int last_dir = -1;
  };

  string findShortestWay(vector<vector<int>>& maze, vector<int>& ball,
                         vector<int>& hole) {
    const int m = maze.size();
    const int n = maze[0].size();

    const auto is_wall = [m, n, &maze](int i, int j) {
      return i < 0 || i >= m || j < 0 || j >= n || maze[i][j] == 1;
    };

    vector<vector<vector<Value>>> values(
        m, vector<vector<Value>>(n, vector<Value>(4)));
    deque<tuple<int, int, int>> q;
    for (int k = 0; k < kDirs.size(); ++k) {
      values[ball[0]][ball[1]][k].dist = 0;
      q.emplace_back(ball[0], ball[1], k);
    }
    vector<tuple<int, int, int>> nexts;
    nexts.reserve(kDirs.size());
    while (!q.empty()) {
      auto [i, j, k] = q.front();
      q.pop_front();
      if (i == hole[0] && j == hole[1]) {
        return createPath(values, i, j, k);
      }
      int next_i = i + kDirs[k].first;
      int next_j = j + kDirs[k].second;
      nexts.clear();
      if (!is_wall(next_i, next_j)) {
        nexts.emplace_back(next_i, next_j, k);
      } else {
        for (int kk = 0; kk < kDirs.size(); ++kk) {
          next_i = i + kDirs[kk].first;
          next_j = j + kDirs[kk].second;
          if (!is_wall(next_i, next_j)) {
            nexts.emplace_back(next_i, next_j, kk);
          }
        }
      }
      for (auto [ii, jj, kk] : nexts) {
        if (values[ii][jj][kk].dist == INT_MAX) {
          values[ii][jj][kk].dist = values[i][j][k].dist + 1;
          values[ii][jj][kk].last_dir = k;
          q.emplace_back(ii, jj, kk);
        }
      }
    }
    return "impossible";
  }

 private:
  string createPath(const vector<vector<vector<Value>>> values, int i, int j,
                    int k) {
    string path;
    path.reserve(values[i][j][k].dist);
    while (values[i][j][k].last_dir >= 0) {
      if (path.empty() || path.back() != kDirNames[k]) {
        path.push_back(kDirNames[k]);
      }
      const int next_k = values[i][j][k].last_dir;
      i -= kDirs[k].first;
      j -= kDirs[k].second;
      k = next_k;
    }
    reverse(path.begin(), path.end());
    return path;
  }
};
