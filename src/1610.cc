class Solution {
 public:
  int visiblePoints(vector<vector<int>>& points, int angle,
                    vector<int>& location) {
    constexpr auto diff = [](double to, double from) {
      return (to >= from) ? to - from : to - from + 360;
    };

    int min_visible = 0;
    vector<pair<double, int>> ordered_points;
    ordered_points.reserve(points.size());
    for (int i = 0; i < points.size(); ++i) {
      if (points[i] == location) {
        ++min_visible;
        continue;
      }
      ordered_points.emplace_back(
          atan2(points[i][1] - location[1], points[i][0] - location[0]) * 180 /
              M_PI,
          i);
    }
    sort(ordered_points.begin(), ordered_points.end());
    const int n = ordered_points.size();
    int result = 0;
    for (int i = 0, span = 1; i < n; ++i, --span) {
      for (; span < n; ++span) {
        if (diff(ordered_points[(i + span) % n].first,
                 ordered_points[i].first) > angle) {
          break;
        }
      }
      result = max(result, span);
    }
    return result + min_visible;
  }
};
