class Solution {
 public:
  int minimumDeviation(vector<int>& nums) {
    const int n = nums.size();
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; ++i) {
      int num = nums[i] % 2 == 0 ? nums[i] : nums[i] * 2;
      while (true) {
        pairs.emplace_back(num, i);
        if (num % 2 == 1) {
          break;
        }
        num /= 2;
      }
    }
    sort(pairs.begin(), pairs.end());
    unordered_map<int, int> cnts;
    map<int, int> tree;
    int result = INT_MAX;
    for (int i = 0, j = 0; j < pairs.size(); ++j) {
      ++cnts[pairs[j].second];
      ++tree[pairs[j].first];
      while (!tree.empty() && cnts.size() == n) {
        result = min(result, tree.rbegin()->first - tree.begin()->first);
        if (--cnts[pairs[i].second] == 0) {
          cnts.erase(pairs[i].second);
        }
        if (--tree[pairs[i].first] == 0) {
          tree.erase(pairs[i].first);
        }
        ++i;
      }
    }
    return result;
  }
};
