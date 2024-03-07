class Solution {
 public:
  int kIncreasing(vector<int>& arr, int k) {
    const int n = arr.size();
    vector<int> dp;
    dp.reserve(n);
    int result = 0;
    for (int offset = 0; offset < k; ++offset) {
      dp.clear();
      int cnt = 0;
      for (int i = offset; i < n; i += k) {
        auto it = upper_bound(dp.begin(), dp.end(), arr[i]);
        if (it == dp.end()) {
          dp.push_back(arr[i]);
        } else {
          *it = min(*it, arr[i]);
        }
        ++cnt;
      }
      result += cnt - dp.size();
    }
    return result;
  }
};
