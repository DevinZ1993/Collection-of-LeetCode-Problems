class Solution {
 public:
  long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums1.size();
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
      indices[nums2[i]] = i;
    }
    vector<int> fenwick(n + 1);

    const auto query = [&fenwick](int i) {
      ++i;
      int result = 0;
      for (; i > 0; i &= (i - 1)) {
        result += fenwick[i];
      }
      return result;
    };

    const auto increment = [&fenwick](int i) {
      ++i;
      for (; i < fenwick.size(); i += (i & (-i))) {
        ++fenwick[i];
      }
    };

    vector<int> lefts(n);
    for (int i = 0; i < n; ++i) {
      int index = indices[nums1[i]];
      if (index > 0) {
        lefts[i] = query(index - 1);
      }
      increment(index);
    }
    fill(fenwick.begin(), fenwick.end(), 0);
    long long result = 0;
    for (int i = n - 1; i >= 0; --i) {
      int index = indices[nums1[i]];
      if (index < n - 1) {
        result += 1LL * lefts[i] * (query(n - 1) - query(index));
      }
      increment(index);
    }
    return result;
  }
};
