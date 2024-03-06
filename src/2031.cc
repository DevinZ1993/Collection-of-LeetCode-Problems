class Solution {
 public:
  int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
    constexpr int mod = 1'000'000'007;
    unordered_map<int, int> cnts;
    cnts.emplace(0, 1);
    int result = 0;
    int more = 0;
    int state = 0;
    for (int num : nums) {
      if (num == 0) {
        more -= cnts[--state];
      } else {
        more += cnts[state++];
      }
      ++cnts[state];
      result = (result + more) % mod;
    }
    return result;
  }
};
