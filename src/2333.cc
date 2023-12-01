class Solution {
 public:
  long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                             int k2) {
    vector<long long> diffs(nums1.size() + 1);
    for (int i = 0; i < nums1.size(); ++i) {
      diffs[i] = abs(nums1[i] - nums2[i]);
    }
    sort(diffs.rbegin(), diffs.rend());
    int budget = k1 + k2;
    for (int i = 0; i + 1 < diffs.size(); ++i) {
      if (diffs[i + 1] == diffs[i]) {
        continue;
      }
      if (budget <= (diffs[i] - diffs[i + 1]) * (i + 1LL)) {
        long long result = 0;
        for (int j = 0; j <= i; ++j) {
          const long long delta = diffs[i] - (budget + j) / (i + 1);
          result += delta * delta;
        }
        for (int j = i + 1; j < diffs.size(); ++j) {
          result += 1LL * diffs[j] * diffs[j];
        }
        return result;
      }
      budget -= (diffs[i] - diffs[i + 1]) * (i + 1);
    }
    return 0;
  }
};
