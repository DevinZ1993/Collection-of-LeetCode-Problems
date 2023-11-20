class Solution {
 public:
  int minKnightMoves(int x, int y) {
    if (x == 0 && y == 0) {
      return 0;
    }
    constexpr array<pair<int, int>, 8> kDirs = {{{-1, -2},
                                                 {-2, -1},
                                                 {1, -2},
                                                 {-2, 1},
                                                 {-1, 2},
                                                 {2, -1},
                                                 {1, 2},
                                                 {2, 1}}};
    const auto eval_h = [x, y](int i, int j) -> double {
      return (abs(x - i) + abs(y - j)) / 3.0;
    };
    struct PairHash {
      size_t operator()(const pair<int, int> &item) const {
        return hash<int>()(item.first) ^ hash<int>()(item.second);
      }
    };
    unordered_map<pair<int, int>, int, PairHash> dists;
    dists[{0, 0}] = 0;
    priority_queue<tuple<double, int, int>> q;
    q.emplace(-eval_h(0, 0), 0, 0);
    while (!q.empty()) {
      const auto [neg_dist, i, j] = q.top();
      q.pop();
      const int dist = dists.at({i, j});
      if (i == x && j == y) {
        return dist;
      }
      if (-neg_dist > dist + eval_h(i, j)) {
        continue;
      }
      for (const auto [di, dj] : kDirs) {
        const auto next_key = make_pair(i + di, j + dj);
        auto dist_it = dists.find(next_key);
        if (dist_it == dists.end() || dist_it->second > dist + 1) {
          dists[next_key] = dist + 1;
          q.emplace(-dist - 1 - eval_h(i + di, j + dj), i + di, j + dj);
        }
      }
    }
    return -1;
  }
};
