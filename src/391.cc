class Solution {
 public:
  bool isRectangleCover(vector<vector<int>> &rectangles) {
    long long area = 0;
    long long min_x = LLONG_MAX;
    long long max_x = LLONG_MIN;
    long long min_y = LLONG_MAX;
    long long max_y = LLONG_MIN;
    for (const auto &rect : rectangles) {
      min_x = min<long long>(min_x, rect[0]);
      max_x = max<long long>(max_x, rect[2]);
      min_y = min<long long>(min_y, rect[1]);
      max_y = max<long long>(max_y, rect[3]);
      area += (0LL + rect[2] - rect[0]) * (0LL + rect[3] - rect[1]);
    }
    if (area != (max_x - min_x) * (max_y - min_y)) {
      return false;
    }

    sort(rectangles.begin(), rectangles.end(),
         [](const auto &a, const auto &b) {
           if (a[1] != b[1]) {
             return a[1] < b[1];
           }
           return a[0] < b[0];
         });

    map<long long, long long> tree;
    tree.emplace(min_x, min_y);
    for (const auto &rect : rectangles) {
      const long long x1 = rect[0];
      const long long y1 = rect[1];
      const long long x2 = rect[2];
      const long long y2 = rect[3];
      auto next_it = tree.upper_bound(x1);
      assert(next_it != tree.begin());
      auto it = prev(next_it);
      if (it->second != y1) {
        return false;
      }
      if (next_it != tree.end() && next_it->first < x2) {
        return false;
      }
      if (next_it == tree.end() || next_it->first > x2) {
        tree.emplace(x2, y1);
      } else if (next_it->second == y2) {
        tree.erase(next_it);
      }
      if (it->first == x1) {
        if (it == tree.begin() || prev(it)->second != y2) {
          it->second = y2;
        } else {
          tree.erase(it);
        }
      } else {
        tree.emplace(x1, y2);
      }
    }
    return tree.size() == 2;
  }
};
