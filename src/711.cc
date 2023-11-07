class Solution {
 public:
  int numDistinctIslands2(vector<vector<int>> &grid) {
    constexpr array<pair<int, int>, 4> kDirs = {
        {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};
    struct VectHasher {
      size_t operator()(const vector<pair<int, int>> &vect) const {
        static const hash<int> int_hasher;
        size_t result = 0;
        for (const auto [x, y] : vect) {
          result = 57 * result + (int_hasher(x) ^ int_hasher(y));
        }
        return result;
      }
    };
    unordered_set<vector<pair<int, int>>, VectHasher> hash_set;

    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n));
    vector<pair<int, int>> stk;
    vector<pair<int, int>> island;
    vector<pair<int, int>> key;
    int result = 0;
    for (int start_i = 0; start_i < m; ++start_i) {
      for (int start_j = 0; start_j < n; ++start_j) {
        if (grid[start_i][start_j] != 1 || vis[start_i][start_j]) {
          continue;
        }
        island.clear();
        vis[start_i][start_j] = true;
        stk.emplace_back(start_i, start_j);
        while (!stk.empty()) {
          const auto [i, j] = stk.back();
          stk.pop_back();
          island.emplace_back(i, j);
          for (const auto [di, dj] : kDirs) {
            const int next_i = i + di;
            const int next_j = j + dj;
            if (next_i >= 0 && next_i < m && next_j >= 0 && next_j < n &&
                grid[next_i][next_j] == 1 && !vis[next_i][next_j]) {
              vis[next_i][next_j] = true;
              stk.emplace_back(next_i, next_j);
            }
          }
        }
        for (int type = 0; type < 8; ++type) {
          key.clear();
          for (const auto &point : island) {
            key.push_back(transform(point, type));
          }
          normalize(key);
          const bool inserted = hash_set.insert(key).second;
          if (type > 0) {
            continue;
          }
          if (!inserted) {
            break;
          }
          ++result;
        }
      }
    }
    return result;
  }

 private:
  void normalize(vector<pair<int, int>> &vect) {
    sort(vect.begin(), vect.end());
    for (int i = 0; i + 1 < vect.size(); ++i) {
      vect[i].first -= vect.back().first;
      vect[i].second -= vect.back().second;
    }
    vect.pop_back();
  }

  pair<int, int> transform(const pair<int, int> &point, int type) {
    auto result = point;
    if (type & 4) {
      swap(result.first, result.second);
    }
    if (type & 1) {
      result.first = -result.first;
    }
    if (type & 2) {
      result.second = -result.second;
    }
    return result;
  }
};
