class Solution {
 public:
  long long countPairs(vector<int>& nums, int k) {
    long long result = 0;
    array<long long, 100'001> divisors{};
    for (int num : nums) {
      result += divisors[k / gcd(num, k)];
      for (int i = 1; i * i <= num; ++i) {
        if (num % i != 0) {
          continue;
        }
        ++divisors[i];
        if (i * i != num) {
          ++divisors[num / i];
        }
      }
    }
    return result;
  }

 private:
  int gcd(int a, int b) {
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
