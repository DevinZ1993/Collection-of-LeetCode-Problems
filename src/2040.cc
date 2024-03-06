class Solution {
 public:
  long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                               long long k) {
    const long long n1 = nums1.size();
    const long long n2 = nums2.size();
    const auto [zero_it1, positive_it1] =
        equal_range(nums1.begin(), nums1.end(), 0);
    const auto [zero_it2, positive_it2] =
        equal_range(nums2.begin(), nums2.end(), 0);
    const long long negatives1 = distance(nums1.begin(), zero_it1);
    const long long zeros1 = distance(nums1.begin(), positive_it1) - negatives1;
    const long long positives1 = n1 - negatives1 - zeros1;
    const long long negatives2 = distance(nums2.begin(), zero_it2);
    const long long zeros2 = distance(nums2.begin(), positive_it2) - negatives2;
    const long long positives2 = n2 - negatives2 - zeros2;
    long long negative_prods =
        negatives1 * positives2 + negatives2 * positives1;
    long long zero_prods = zeros1 * n2 + zeros2 * (positives1 + negatives1);
    if (k <= negative_prods) {
      long long min_value = LLONG_MIN;
      long long max_value = -1;
      while (min_value < max_value) {
        const long long mid_value = min_value + (max_value - min_value) / 2;
        long long cnt = 0;
        // num1 positive, num2 negative
        for (long long i = negatives1 + zeros1, j = 0; i < n1; ++i) {
          while (j < negatives2 + zeros2 &&
                 1LL * nums1[i] * nums2[j] <= mid_value) {
            ++j;
          }
          cnt += j;
        }
        // num2 positive, num1 negative
        for (long long i = negatives2 + zeros2, j = 0; i < n2; ++i) {
          while (j < negatives1 + zeros1 &&
                 1LL * nums1[j] * nums2[i] <= mid_value) {
            ++j;
          }
          cnt += j;
        }
        if (cnt >= k) {
          max_value = mid_value;
        } else {
          min_value = mid_value + 1;
        }
      }
      return min_value;
    } else if (k > negative_prods + zero_prods) {
      k -= (negative_prods + zero_prods);
      long long min_value = 1;
      long long max_value = LLONG_MAX;
      while (min_value < max_value) {
        const long long mid_value = min_value + (max_value - min_value) / 2;
        long long cnt = 0;
        // num1 positive, num2 positive
        for (long long i = negatives1 + zeros1, j = n2 - 1; i < n1; ++i) {
          while (j >= negatives2 + zeros2 &&
                 1LL * nums1[i] * nums2[j] > mid_value) {
            --j;
          }
          cnt += (j - negatives2 - zeros2 + 1);
        }
        // num1 negative, num2 negative
        for (long long i = negatives1 - 1, j = 0; i >= 0; --i) {
          while (j < negatives2 && 1LL * nums1[i] * nums2[j] > mid_value) {
            ++j;
          }
          cnt += (negatives2 - j);
        }
        if (cnt >= k) {
          max_value = mid_value;
        } else {
          min_value = mid_value + 1;
        }
      }
      return min_value;
    }
    return 0;
  }
};
