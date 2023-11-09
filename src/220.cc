class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                     int valueDiff) {
    const auto get_key = [valueDiff](int val) {
      return val / max<long long>(1, valueDiff);
    };

    unordered_map<long long, long long> buckets;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > indexDiff) {
        buckets.erase(get_key(nums[i - indexDiff - 1]));
      }
      const long long current_key = get_key(nums[i]);
      for (long long key :
           vector{current_key - 1, current_key, current_key + 1}) {
        auto it = buckets.find(key);
        if (it != buckets.end() && abs(it->second - nums[i]) <= valueDiff) {
          return true;
        }
      }
      buckets[current_key] = nums[i];
    }
    return false;
  }
};
