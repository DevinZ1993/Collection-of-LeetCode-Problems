class Solution {
 public:
  string smallestGoodBase(string n) {
    long long n_val = stoll(n);
    for (int len = static_cast<int>(ceil(log2(n_val))); len > 2; --len) {
      long long min_base = 2;
      long long max_base = n_val - 1;
      while (min_base < max_base) {
        const long long mid_base = min_base + (max_base - min_base) / 2;
        if (getResidue(mid_base, len, n_val) <= 0) {
          max_base = mid_base;
        } else {
          min_base = mid_base + 1;
        }
      }
      if (getResidue(min_base, len, n_val) == 0) {
        return to_string(min_base);
      }
    }
    return to_string(n_val - 1);
  }

 private:
  long long getResidue(long long base, int len, long long target) const {
    long long pow = 1;
    --target;
    for (int i = 1; i < len; ++i) {
      if (pow > target / base) {
        return -1;
      }
      pow *= base;
      target -= pow;
    }
    return target;
  }
};
