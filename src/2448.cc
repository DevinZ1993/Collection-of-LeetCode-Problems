class Solution {
 public:
  long long minCost(vector<int>& nums, vector<int>& cost) {
    map<int, long long> indices;
    const int n = nums.size();
    for (int i = 0; i < n; ++i) {
      indices[nums[i]] += cost[i];
    }
    auto prev_it = indices.begin();
    long long right_cost = 0;
    long long right_sum = 0;
    for (auto it = next(prev_it); it != indices.end(); ++it) {
      right_cost += (it->first - prev_it->first) * it->second;
      right_sum += it->second;
    }
    long long min_cost = right_cost;
    long long left_cost = 0;
    long long left_sum = 0;
    for (auto it = next(prev_it); it != indices.end(); prev_it = it, ++it) {
      left_sum += prev_it->second;
      left_cost += (it->first - prev_it->first) * left_sum;
      right_cost -= (it->first - prev_it->first) * right_sum;
      right_sum -= it->second;
      min_cost = min(min_cost, left_cost + right_cost);
    }
    return min_cost;
  }
};
