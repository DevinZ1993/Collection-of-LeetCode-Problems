class Solution {
 public:
  int numPoints(vector<vector<int>>& darts, int r) {
    const int n = darts.size();
    const double r_squared = 1.0 * r * r;
    constexpr double kEpsilon = 1.0e-6;
    const auto count = [&darts, r_squared](double x, double y) {
      int result = 0;
      for (const auto& dart : darts) {
        const double dx = x - dart[0];
        const double dy = y - dart[1];
        if (dx * dx + dy * dy <= r_squared + kEpsilon) {
          ++result;
        }
      }
      return result;
    };
    int result = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        const double dx = darts[j][0] - darts[i][0];
        const double dy = darts[j][1] - darts[i][1];
        const double dist_squared = dx * dx + dy * dy;
        if (dist_squared > 4.0 * r_squared) {
          continue;
        }
        const double ratio =
            sqrt((r_squared - 0.25 * dist_squared) / dist_squared);
        result = max(result, count(darts[i][0] + 0.5 * dx + ratio * dy,
                                   darts[i][1] + 0.5 * dy - ratio * dx));
        result = max(result, count(darts[i][0] + 0.5 * dx - ratio * dy,
                                   darts[i][1] + 0.5 * dy + ratio * dx));
      }
    }
    return result;
  }
};
