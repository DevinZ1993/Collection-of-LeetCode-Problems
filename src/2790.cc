// Inspired by
// https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length/discuss/3803904/JavaC%2B%2BPython-Math-O(n)
class Solution {
 public:
  int maxIncreasingGroups(vector<int>& usageLimits) {
    sort(usageLimits.begin(), usageLimits.end());
    int count = 0;
    long long sum = 0;
    for (int limit : usageLimits) {
      sum += limit;
      if (sum >= (1LL + count) * (2LL + count) / 2) {
        ++count;
      }
    }
    return count;
  }
};
