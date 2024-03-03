class Solution {
 public:
  int countDifferentSubsequenceGCDs(vector<int>& nums) {
    constexpr auto gcd = [](int a, int b) {
      if (a > b) {
        swap(a, b);
      }
      while (a > 0) {
        b %= a;
        swap(a, b);
      }
      return b;
    };
    array<int, 200'001> factors{};
    for (int num : nums) {
      for (int i = 1; i * i <= num; ++i) {
        if (num % i != 0) {
          continue;
        }
        if (factors[i] == 0) {
          factors[i] = num;
        } else {
          factors[i] = gcd(factors[i], num);
        }
        if (i * i == num) {
          continue;
        }
        const int j = num / i;
        if (factors[j] == 0) {
          factors[j] = num;
        } else {
          factors[j] = gcd(factors[j], num);
        }
      }
    }
    int result = 0;
    for (int i = 1; i < factors.size(); ++i) {
      if (factors[i] == i) {
        ++result;
      }
    }
    return result;
  }
};
