class Solution {
 public:
  int maximumANDSum(vector<int> &nums, int numSlots) {
    unordered_map<int, int> dp;
    unordered_map<int, int> last_dp;
    dp.insert({0, 0});
    for (int num : nums) {
      swap(dp, last_dp);
      dp.clear();
      for (const auto &[state, val] : last_dp) {
        for (int i = 0; i < numSlots; ++i) {
          const int mask = (3 << (2 * i));
          if ((state & mask) == mask) {
            continue;
          }
          const int next_val = (num & (i + 1)) + val;
          const int next_state = ((state & mask) == (1 << (2 * i)))
                                     ? (state | mask)
                                     : (state | (1 << (2 * i)));
          if (auto it = dp.find(next_state); it == dp.end()) {
            dp.insert({next_state, next_val});
          } else {
            it->second = max(it->second, next_val);
          }
        }
      }
    }
    int result = INT_MIN;
    for (const auto &[_, val] : dp) {
      result = max(result, val);
    }
    return result;
  }
};
