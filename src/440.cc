class Solution {
 public:
  int findKthNumber(int n, int k) {
    int prefix = 0;
    while (k > 0) {
      prefix *= 10;
      for (int digit = 0; digit <= 9; ++digit, ++prefix) {
        if (prefix == 0 && digit == 0) {
          continue;
        }
        long long count = 0;
        for (long long pow = 1; prefix * pow <= n; pow *= 10) {
          count += min(pow, n - prefix * pow + 1);
        }
        if (k <= count) {
          --k;
          break;
        }
        k -= count;
      }
    }
    return prefix;
  }
};
