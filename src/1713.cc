class Solution {
 public:
  int minOperations(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> indices;
    for (int i = 0; i < target.size(); ++i) {
      indices.emplace(target[i], i);
    }
    vector<int> dp;
    for (int num : arr) {
      auto index_it = indices.find(num);
      if (index_it == indices.end()) {
        continue;
      }
      const int index = index_it->second;
      auto it = lower_bound(dp.begin(), dp.end(), index);
      if (it == dp.end()) {
        dp.push_back(index);
      } else {
        *it = index;
      }
    }
    return target.size() - dp.size();
  }
};
