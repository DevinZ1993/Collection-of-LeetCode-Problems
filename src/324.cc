class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    const int n = nums.size();

    const auto get_num = [&nums, n](int index) -> int& {
      if (index < (n + 1) / 2) {
        return nums[((n + 1) / 2 - index - 1) * 2];
      }
      index -= (n + 1) / 2;
      return nums[(n / 2 - 1 - index) * 2 + 1];
    };
    random_shuffle(nums.begin(), nums.end());
    const int index = (n + 1) / 2 - 1;
    for (int min_index = 0, max_index = n - 1; min_index < max_index;) {
      int i = min_index;
      int j = min_index;
      int k = max_index;
      const int pivot = get_num(max_index);
      while (j < k) {
        if (get_num(j) < pivot) {
          swap(get_num(i++), get_num(j++));
        } else if (get_num(j) == pivot) {
          ++j;
        } else {
          swap(get_num(j), get_num(--k));
        }
      }
      swap(get_num(j), get_num(max_index));
      if (index >= i && index <= j) {
        break;
      }
      if (index > j) {
        min_index = j + 1;
      } else {
        max_index = i - 1;
      }
    }
  }
};
