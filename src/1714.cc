class Solution {
 public:
  vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) {
    constexpr int mod = 1'000'000'007;
    const int n = nums.size();
    const int m = static_cast<int>(sqrt(1.0 * n));
    vector<vector<int>> sums(n, vector<int>(m));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j < sums[i].size(); ++j) {
        sums[i][j] = nums[i];
        if (i + j + 1 < n) {
          sums[i][j] = (sums[i][j] + sums[i + j + 1][j]) % mod;
        }
      }
    }
    vector<int> results(queries.size());
    for (int index = 0; index < queries.size(); ++index) {
      if (queries[index][1] - 1 < m) {
        results[index] = sums[queries[index][0]][queries[index][1] - 1];
      } else {
        for (int i = queries[index][0]; i < n; i += queries[index][1]) {
          results[index] = (results[index] + nums[i]) % mod;
        }
      }
    }
    return results;
  }
};
