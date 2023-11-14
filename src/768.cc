class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    vector<int> sorted_arr(arr);
    sort(sorted_arr.begin(), sorted_arr.end());
    int result = 0;
    unordered_map<int, int> cnts;
    for (int i = 0; i < arr.size(); ++i) {
      if (++cnts[arr[i]] == 0) {
        cnts.erase(arr[i]);
      }
      if (--cnts[sorted_arr[i]] == 0) {
        cnts.erase(sorted_arr[i]);
      }
      if (cnts.empty()) {
        ++result;
      }
    }
    return result;
  }
};
