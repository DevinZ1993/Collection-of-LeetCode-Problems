class Solution {
 public:
  int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
    const int n = nums1.size();
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(),
         [&nums2](int i, int j) { return nums2[i] < nums2[j]; });
    vector<vector<int>> dp(n, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
      const int index = indices[i];
      for (int j = 1; j <= i; ++j) {
        dp[i][j] = max(dp[i - 1][j],
                       dp[i - 1][j - 1] + j * nums2[index] + nums1[index]);
      }
      dp[i][i + 1] =
          (i == 0 ? 0 : dp[i - 1][i]) + (i + 1) * nums2[index] + nums1[index];
    }
    int sum = accumulate(nums1.begin(), nums1.end(), 0);
    const int inc = accumulate(nums2.begin(), nums2.end(), 0);
    for (int j = 0; j <= n; ++j) {
      for (int i = 0; i < n; ++i) {
        if (sum - dp[i][j] <= x) {
          return j;
        }
      }
      sum += inc;
    }
    return -1;
  }
};
