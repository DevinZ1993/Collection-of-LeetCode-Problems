class Solution {
 public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    const int n = arr.size();
    int right = n - 1;
    while (right > 0 && arr[right] >= arr[right - 1]) {
      --right;
    }
    if (right == 0) {
      return 0;
    }
    int result = n;
    int i = 0;
    for (int j = right; j < n; ++j) {
      while ((i == 0 || arr[i] >= arr[i - 1]) && arr[i] <= arr[j]) {
        ++i;
      }
      result = min(result, j - i);
    }
    while (i == 0 || arr[i] >= arr[i - 1]) {
      ++i;
    }
    result = min(result, n - i);
    return result;
  }
};
