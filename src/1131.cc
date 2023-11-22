class Solution {
 public:
  int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
    constexpr array<pair<int, int>, 4> kSigns = {
        {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}};
    array<int, kSigns.size()> min_vals;
    for (int i = 0; i < kSigns.size(); ++i) {
      min_vals[i] = kSigns[i].first * arr1[0] + kSigns[i].second * arr2[0];
    }
    const int n = arr1.size();
    int result = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < kSigns.size(); ++j) {
        const int value =
            kSigns[j].first * arr1[i] + kSigns[j].second * arr2[i] + i;
        result = max(result, value - min_vals[j]);
        min_vals[j] = min(min_vals[j], value);
      }
    }
    return result;
  }
};
