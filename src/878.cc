class Solution {
 public:
  int nthMagicalNumber(int n, int a, int b) {
    long long min_val = min(a, b);
    long long max_val = 1LL * max(a, b) * n;
    const long long g = 1LL * a * b / gcd(a, b);
    while (min_val < max_val) {
      const long long mid_val = min_val + (max_val - min_val) / 2;
      if (mid_val / a + mid_val / b - mid_val / g < n) {
        min_val = mid_val + 1;
      } else {
        max_val = mid_val;
      }
    }
    return min_val % 1'000'000'007;
  }

 private:
  int gcd(int a, int b) const {
    if (a > b) {
      swap(a, b);
    }
    while (a > 0) {
      b %= a;
      swap(a, b);
    }
    return b;
  }
};
