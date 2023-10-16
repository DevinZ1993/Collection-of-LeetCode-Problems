class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    const int n = nums.size();
    vector<int> sorted_nums(nums.begin(), nums.end());
    sort(sorted_nums.begin(), sorted_nums.end());
    unordered_map<int, int> indices;
    for (int i = 0; i < n; ++i) {
      indices.emplace(sorted_nums[i], i);
    }
    vector<int> fenwick(n + 1);
    vector<int> results(n);
    for (int i = n - 1; i >= 0; --i) {
      const int index = indices.at(nums[i]);
      for (int j = index; j > 0; j &= (j - 1)) {
        results[i] += fenwick[j];
      }
      for (int j = index + 1; j < n; j += (j & (-j))) {
        ++fenwick[j];
      }
    }
    return results;
  }
};
