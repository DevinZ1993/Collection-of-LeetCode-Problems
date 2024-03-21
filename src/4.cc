class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    const int k = (n1 + n2) / 2;
    if (n1 % 2 != n2 % 2) {
      return solve(nums1, 0, n1 - 1, nums2, 0, n2 - 1, k + 1);
    }
    return 0.5 * (solve(nums1, 0, n1 - 1, nums2, 0, n2 - 1, k) +
                  solve(nums1, 0, n1 - 1, nums2, 0, n2 - 1, k + 1));
  }

 private:
  int solve(const vector<int>& nums1, int min_index1, int max_index1,
            const vector<int>& nums2, int min_index2, int max_index2, int k) {
    max_index1 = min(max_index1, min_index1 + k - 1);
    max_index2 = min(max_index2, min_index2 + k - 1);
    if (max_index1 - min_index1 < max_index2 - min_index2) {
      return solve(nums2, min_index2, max_index2, nums1, min_index1, max_index1,
                   k);
    }
    if (min_index2 > max_index2) {
      return nums1[min_index1 + k - 1];
    }
    if (max_index1 == min_index1) {
      return k == 1 ? min(nums1[min_index1], nums2[min_index2])
                    : max(nums1[min_index1], nums2[min_index2]);
    }
    const int mid_index1 = min_index1 + (max_index1 - min_index1) / 2;
    const int mid_index2 =
        distance(nums2.begin(), lower_bound(nums2.begin() + min_index2,
                                            nums2.begin() + max_index2 + 1,
                                            nums1[mid_index1]));
    const int rank = mid_index1 - min_index1 + 1 + mid_index2 - min_index2;
    if (rank == k) {
      return nums1[mid_index1];
    } else if (rank > k) {
      return solve(nums1, min_index1, mid_index1 - 1, nums2, min_index2,
                   mid_index2 - 1, k);
    } else {
      return solve(nums1, mid_index1 + 1, max_index1, nums2, mid_index2,
                   max_index2, k - rank);
    }
  }
};
