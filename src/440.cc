class Solution {
 public:
  int findKthNumber(int n, int k) {
    int prefix = 0;
    while (k > 0) {
      prefix *= 10;
      for (int digit = (prefix == 0 ? 1 : 0); digit <= 9; ++digit) {
        const int sub = count(prefix + digit, n);
        if (sub >= k) {
          prefix += digit;
          --k;
          break;
        }
        k -= sub;
      }
    }
    return prefix;
  }

 private:
  int count(long long prefix, int n) {
    long long pow = 1;
    long long result = 0;
    while (prefix <= n) {
      result += min(pow, n - prefix + 1);
      prefix *= 10;
      pow *= 10;
    }
    return result;
  }
};
