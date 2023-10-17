class Solution {
 public:
  bool splitArraySameAverage(vector<int>& nums) {
    const long long n = nums.size();
    if (n == 1) {
      return false;
    }

    long long sum = 0;
    for (int num : nums) {
      sum += num;
    }

    vector<long long> left_sums(1 << (n / 2));
    unordered_map<long long, int> cnts;
    for (int state = 1; state < left_sums.size(); ++state) {
      for (int i = 0; i < n / 2; ++i) {
        if (state & (1 << i)) {
          left_sums[state] = left_sums[state & ~(1 << i)] + (n * nums[i] - sum);
          break;
        }
      }
      if (left_sums[state] == 0) {
        return true;
      }
      ++cnts[left_sums[state]];
    }

    vector<double> right_sums(1 << ((n + 1) / 2));
    for (int state = 1; state < right_sums.size(); ++state) {
      for (int i = 0; i < (n + 1) / 2; ++i) {
        if (state & (1 << i)) {
          right_sums[state] =
              right_sums[state & ~(1 << i)] + (n * nums[i + n / 2] - sum);
          break;
        }
      }
      if (right_sums[state] == 0) {
        return true;
      }

      auto it = cnts.find(-right_sums[state]);
      if (it == cnts.end()) {
        continue;
      }
      if (it->second > 1 || left_sums.back() != -right_sums[state]) {
        return true;
      }
    }
    return false;
  }
};
