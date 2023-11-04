class Solution {
 public:
  int findNthDigit(int n) {
    int len = 1;
    long long pow = 1;
    while (len * 9 * pow < n) {
      n -= len * 9 * pow;
      ++len;
      pow *= 10;
    }
    --n;
    return to_string(pow + n / len)[n % len] - '0';
  }
};
