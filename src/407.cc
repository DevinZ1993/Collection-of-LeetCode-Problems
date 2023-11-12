class Solution {
 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    const int m = heightMap.size();
    const int n = heightMap[0].size();
    vector<vector<int>> heights(m, vector<int>(n, -1));
    priority_queue<tuple<int, int, int>> q;
    for (int i = 0; i < m; ++i) {
      heights[i][0] = heightMap[i][0];
      q.emplace(-heights[i][0], i, 0);
      if (n > 1) {
        heights[i][n - 1] = heightMap[i][n - 1];
        q.emplace(-heights[i][n - 1], i, n - 1);
      }
    }
    for (int j = 1; j < n - 1; ++j) {
      heights[0][j] = heightMap[0][j];
      q.emplace(-heights[0][j], 0, j);
      if (m > 1) {
        heights[m - 1][j] = heightMap[m - 1][j];
        q.emplace(-heights[m - 1][j], m - 1, j);
      }
    }
    constexpr array<pair<int, int>, 4> kDirs = {
        {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};
    int result = 0;
    while (!q.empty()) {
      auto [_, i, j] = q.top();
      q.pop();
      for (const auto [di, dj] : kDirs) {
        const int next_i = i + di;
        const int next_j = j + dj;
        if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n ||
            heights[next_i][next_j] >= 0) {
          continue;
        }
        heights[next_i][next_j] = max(heightMap[next_i][next_j], heights[i][j]);
        q.emplace(-heights[next_i][next_j], next_i, next_j);
        result += heights[next_i][next_j] - heightMap[next_i][next_j];
      }
    }
    return result;
  }
};
