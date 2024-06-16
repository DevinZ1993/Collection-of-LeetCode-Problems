class Solution {
 public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    const int n = arr.size();
    int j = n - 1;
    while (j > 0 && arr[j - 1] <= arr[j]) {
      --j;
    }
    if (j == 0) {
      return 0;
    }
    int result = j;
    for (int i = 0;; ++i) {
      while (j < n && arr[j] < arr[i]) {
        ++j;
      }
      result = min(result, j - i - 1);
      if (arr[i + 1] < arr[i]) {
        break;
      }
    }
    return result;
  }
};
