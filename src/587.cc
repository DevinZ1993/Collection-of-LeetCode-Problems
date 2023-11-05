class Solution {
 public:
  vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
    const auto cross_product = [&trees](int i, int j, int k) {
      long long x1 = trees[j][0] - trees[i][0];
      long long y1 = trees[j][1] - trees[i][1];
      long long x2 = trees[k][0] - trees[j][0];
      long long y2 = trees[k][1] - trees[j][1];
      return x1 * y2 - x2 * y1;
    };
    if (auto min_it = min_element(trees.begin(), trees.end());
        min_it != trees.begin()) {
      swap(trees[0], *min_it);
    }
    sort(trees.begin() + 1, trees.end(),
         [&zero = trees[0]](const auto &a, const auto &b) {
           long long angle1 = 1LL * (b[0] - zero[0]) * (a[1] - zero[1]);
           long long angle2 = 1LL * (a[0] - zero[0]) * (b[1] - zero[1]);
           if (angle1 != angle2) {
             return angle1 < angle2;
           }
           long long dist1 = a[0] + abs(a[1] - zero[1]);
           long long dist2 = b[0] + abs(b[1] - zero[1]);
           return dist1 < dist2;
         });
    vector<int> hull;
    hull.reserve(trees.size());
    for (int i = 0; i < trees.size(); ++i) {
      while (hull.size() >= 2 &&
             cross_product(hull[hull.size() - 2], hull.back(), i) < 0) {
        hull.pop_back();
      }
      hull.push_back(i);
    }
    unordered_set<int> hull_indices(hull.begin(), hull.end());
    // Have to add the points on the last edge if they are not added yet.
    for (int i = 0; i < trees.size(); ++i) {
      if (cross_product(0, hull.back(), i) == 0) {
        hull_indices.insert(i);
      }
    }
    vector<vector<int>> results;
    results.reserve(hull_indices.size());
    for (int index : hull_indices) {
      results.push_back(move(trees[index]));
    }
    return results;
  }
};
