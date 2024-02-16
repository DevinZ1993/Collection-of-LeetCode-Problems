class Solution {
 public:
  int minOrAfterOperations(vector<int>& nums, int k) {
    int result = 0;
    for (int offset = 29; offset >= 0; --offset) {
      const int bit = (1 << offset);
      int cnt = 0;
      const int target = (result | (bit - 1));
      int and_result = (1 << 30) - 1;
      for (int num : nums) {
        and_result &= num;
        if ((and_result & target) == and_result) {
          and_result = (1 << 30) - 1;
        } else {
          ++cnt;
        }
      }
      if (cnt > k) {
        result |= bit;
      }
    }
    return result;
  }
};
