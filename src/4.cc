class Solution {
 public:
  struct Slice {
    explicit Slice(const vector<int> *nums, int min_index, int max_index)
        : nums(*nums), min_index(min_index), max_index(max_index) {}

    int get(int index) const { return nums[min_index + index]; }

    int size() const { return max_index - min_index + 1; }

    auto begin() const { return nums.begin() + min_index; }

    auto end() const { return nums.begin() + max_index + 1; }

    const vector<int> &nums;
    int min_index;
    int max_index;
  };

  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    const Slice slice1{&nums1, 0, min(n1 - 1, (n1 + n2) / 2)};
    const Slice slice2{&nums2, 0, min(n2 - 1, (n1 + n2) / 2)};
    if (n1 % 2 == n2 % 2) {
      return 0.5 * (findMedian(slice1, slice2, (n1 + n2) / 2) +
                    findMedian(slice1, slice2, (n1 + n2) / 2 + 1));
    }
    return findMedian(slice1, slice2, (n1 + n2 + 1) / 2);
  }

 private:
  int findMedian(const Slice &slice1, const Slice &slice2, int k) {
    const Slice *slice_ptr1 = &slice1;
    const Slice *slice_ptr2 = &slice2;
    if (slice_ptr1->size() < slice_ptr2->size()) {
      swap(slice_ptr1, slice_ptr2);
    }
    if (slice_ptr2->size() == 0) {
      return slice_ptr1->get(k - 1);
    }
    if (slice_ptr1->size() == 1) {
      const int a = slice_ptr1->get(0);
      const int b = slice_ptr2->get(0);
      return k == 1 ? min(a, b) : max(a, b);
    }
    const int index1 = (slice_ptr1->size() - 1) / 2;
    const auto index2 = static_cast<int>(distance(
        slice_ptr2->begin(), lower_bound(slice_ptr2->begin(), slice_ptr2->end(),
                                         slice_ptr1->get(index1))));
    if (index1 + index2 == k - 1) {
      return slice_ptr1->get(index1);
    }

    if (index1 + index2 < k - 1) {
      const Slice next_slice1{&slice_ptr1->nums,
                              slice_ptr1->min_index + index1 + 1,
                              slice_ptr1->max_index};
      const Slice next_slice2{&slice_ptr2->nums, slice_ptr2->min_index + index2,
                              slice_ptr2->max_index};
      return findMedian(next_slice1, next_slice2, k - index1 - index2 - 1);
    }

    const Slice next_slice1{&slice_ptr1->nums, slice_ptr1->min_index,
                            slice_ptr1->min_index + index1 - 1};
    const Slice next_slice2{&slice_ptr2->nums, slice_ptr2->min_index,
                            slice_ptr2->min_index + index2 - 1};
    return findMedian(next_slice1, next_slice2, k);
  }
};
