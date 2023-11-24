class Solution {
 public:
  bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                    int x2, int y2) {
    if (xCenter >= x1 && xCenter <= x2 && yCenter >= y1 && yCenter <= y2) {
      return true;
    }

    const double squared_radius = 1.0 * radius * radius;

    const auto squared_dist_to_point = [xCenter, yCenter](int x, int y) {
      return 1.0 * (x - xCenter) * (x - xCenter) +
             1.0 * (y - yCenter) * (y - yCenter);
    };
    return squared_dist_to_point(x1, y1) <= squared_radius ||
           squared_dist_to_point(x1, y2) <= squared_radius ||
           squared_dist_to_point(x2, y1) <= squared_radius ||
           squared_dist_to_point(x2, y2) <= squared_radius ||
           (xCenter >= x1 && xCenter <= x2 &&
            min(abs(y1 - yCenter), abs(y2 - yCenter)) <= radius) ||
           (yCenter >= y1 && yCenter <= y2 &&
            min(abs(x1 - xCenter), abs(x2 - xCenter)) <= radius);
  }
};
