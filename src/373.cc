class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    const int m = min<int>(nums1.size(), k);
    const int n = min<int>(nums2.size(), k);
    vector<int> indices(m);
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      q.emplace(-nums1[i] - nums2[0], i);
    }
    vector<vector<int>> results;
    results.reserve(k);
    while (results.size() < k && !q.empty()) {
      const int index = q.top().second;
      q.pop();
      auto& result = results.emplace_back();
      result.push_back(nums1[index]);
      result.push_back(nums2[indices[index]]);
      if (++indices[index] < n) {
        q.emplace(-nums1[index] - nums2[indices[index]], index);
      }
    }
    return results;
  }
};
