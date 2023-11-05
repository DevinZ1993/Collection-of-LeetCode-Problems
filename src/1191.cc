class Solution {
 public:
  int kConcatenationMaxSum(vector<int>& arr, int k) {
    const int n = arr.size();
    long long max_sum = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      if (sum < 0) {
        sum = arr[i];
      } else {
        sum += arr[i];
      }
      max_sum = max(max_sum, sum);
    }
    if (k == 1) {
      return max_sum;
    }
    long long result = max_sum;
    sum = 0;
    long long max_left = 0;
    for (int i = 0; i < n; ++i) {
      sum += arr[i];
      max_left = max(max_left, sum);
    }
    sum = 0;
    long long max_right = 0;
    for (int i = n - 1; i >= 0; --i) {
      sum += arr[i];
      max_right = max(max_right, sum);
    }
    result = max(result, max_left + max_right + (k - 2) * max(0LL, sum));
    return result % 1'000'000'007;
  }
};
