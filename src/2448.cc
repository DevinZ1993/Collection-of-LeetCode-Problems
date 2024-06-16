class Solution {
 public:
  long long minCost(vector<int>& nums, vector<int>& cost) {
    const int n = nums.size();
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(),
         [&nums](int i, int j) { return nums[i] < nums[j]; });
    long long value = 0;
    long long right_cost = 0;
    for (int i = 1; i < n; ++i) {
      value += (0LL + nums[indices[i]] - nums[indices[0]]) * cost[indices[i]];
      right_cost += cost[indices[i]];
    }
    long long result = value;
    long long left_cost = 0;
    for (int i = 1; i < n; ++i) {
      left_cost += cost[indices[i - 1]];
      value += (0LL + left_cost - right_cost) *
               (nums[indices[i]] - nums[indices[i - 1]]);
      right_cost -= cost[indices[i]];
      result = min(result, value);
    }
    return result;
  }
};
