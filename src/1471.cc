class Solution {
 public:
  vector<int> getStrongest(vector<int>& arr, int k) {
    const int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> results;
    results.reserve(k);
    const int median = arr[(n - 1) / 2];
    for (int i = 0, j = n - 1; results.size() < k;) {
      if (median - arr[i] <= arr[j] - median) {
        results.push_back(arr[j--]);
      } else {
        results.push_back(arr[i++]);
      }
    }
    return results;
  }
};
