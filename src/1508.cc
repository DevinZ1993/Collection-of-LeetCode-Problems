class Solution {
 public:
  int rangeSum(vector<int> &nums, int n, int left, int right) {
    vector<long long> sums(n + 1);
    for (int i = 0; i < n; ++i) {
      sums[i + 1] = sums[i] + nums[i];
    }
    vector<long long> sum_of_sums(sums.size() + 1);
    for (int i = 0; i < sums.size(); ++i) {
      sum_of_sums[i + 1] = (sum_of_sums[i] + sums[i]) % mod;
    }
    return (solve(sums, sum_of_sums, right) + mod -
            solve(sums, sum_of_sums, left - 1)) %
           mod;
  }

 private:
  long long solve(const vector<long long> &sums,
                  const vector<long long> &sum_of_sums, int target_count) {
    long long min_sum = 0;
    long long max_sum = sums.back();
    while (min_sum < max_sum) {
      const long long mid_sum = min_sum + (max_sum - min_sum) / 2;
      int count = 0;
      for (int i = 0, j = 1; j < sums.size(); ++j) {
        while (i < j && sums[j] - sums[i] > mid_sum) {
          ++i;
        }
        count += j - i;
      }
      if (count < target_count) {
        min_sum = mid_sum + 1;
      } else {
        max_sum = mid_sum;
      }
    }

    // Note that `min_sum` is the sum at index `target_count` (indexed from 1),
    // which doesn't mean all sums less than or equal to `min_sum` are within
    // the first `target_count` sums, since min_sum may duplicate.
    long long result = 0;
    long long sum_count = target_count;
    for (int i = 0, j = 1; j < sums.size(); ++j) {
      while (i < j && sums[j] - sums[i] >= min_sum) {
        ++i;
      }
      sum_count -= (j - i);
      result = (result + (j - i) * sums[j] % mod) % mod;
      result =
          (result + mod - (sum_of_sums[j] + mod - sum_of_sums[i]) % mod) % mod;
    }
    result = (result + sum_count * min_sum % mod) % mod;
    return result;
  }

  static constexpr long long mod = 1'000'000'007LL;
};
