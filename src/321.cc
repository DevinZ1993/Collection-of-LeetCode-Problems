class Solution {
 public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<int> result;
    result.reserve(k);
    vector<int> candidate;
    candidate.reserve(k);
    for (int m = max(0, k - static_cast<int>(nums2.size()));
         m <= nums1.size() && m <= k; ++m) {
      const int n = k - m;
      vector<int> selected_nums1 = select(nums1, m);
      vector<int> selected_nums2 = select(nums2, n);
      candidate.clear();
      for (int i = 0, j = 0; candidate.size() < k;) {
        if (j == n) {
          candidate.push_back(selected_nums1[i++]);
        } else if (i == m ||
                   compare(selected_nums1, i, selected_nums2, j) <= 0) {
          candidate.push_back(selected_nums2[j++]);
        } else {
          candidate.push_back(selected_nums1[i++]);
        }
      }
      if (result.empty() || result < candidate) {
        swap(result, candidate);
      }
    }
    return result;
  }

 private:
  vector<int> select(const vector<int> &nums, int k) const {
    const int n = nums.size();
    vector<int> results;
    results.reserve(k);
    for (int i = 0; i < n; ++i) {
      while (!results.empty() && results.size() + n - i > k &&
             results.back() < nums[i]) {
        results.pop_back();
      }
      if (results.size() < k) {
        results.push_back(nums[i]);
      }
    }
    assert(results.size() == k);
    return results;
  }

  int compare(const vector<int> &nums1, int i, const vector<int> &nums2,
              int j) const {
    // Memoizing this turns out to be much slower.
    for (; i < nums1.size() && j < nums2.size(); ++i, ++j) {
      if (nums1[i] != nums2[j]) {
        return nums1[i] - nums2[j];
      }
    }
    return (nums1.size() - i) - (nums2.size() - j);
  }
};
