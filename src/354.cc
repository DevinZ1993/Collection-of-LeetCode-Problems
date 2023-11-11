class Solution {
 public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    const int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), [](const auto &a, const auto &b) {
      if (a[0] != b[0]) {
        return a[0] < b[0];
      }
      return a[1] > b[1];
    });
    vector<int> lis;
    for (const auto &envelope : envelopes) {
      auto it = lower_bound(lis.begin(), lis.end(), envelope[1]);
      if (it == lis.end()) {
        lis.push_back(envelope[1]);
      } else {
        *it = envelope[1];
      }
    }
    return lis.size();
  }
};
