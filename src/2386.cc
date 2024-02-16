class Solution {
 public:
  long long kSum(vector<int>& nums, int k) {
    long long max_sum = 0;
    vector<long long> diffs;
    diffs.reserve(nums.size());
    for (int num : nums) {
      if (num > 0) {
        max_sum += num;
      }
      diffs.push_back(abs(num));
    }
    sort(diffs.begin(), diffs.end());
    if (diffs.size() > k) {
      diffs.resize(k);
    }
    priority_queue<pair<long long, int>> q;
    q.emplace(0, 0);
    for (int i = 1; i < k; ++i) {
      const auto [sum, index] = q.top();
      q.pop();
      if (index == diffs.size()) {
        continue;
      }
      if (index > 0) {
        q.emplace(sum + diffs[index - 1] - diffs[index], index + 1);
      }
      q.emplace(sum - diffs[index], index + 1);
    }
    return max_sum + q.top().first;
  }
};
