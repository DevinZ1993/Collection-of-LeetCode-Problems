class Solution {
 public:
  int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
    long long sum = 0;
    for (int num : nums) {
      sum += num;
    }
    const int n = nums.size();
    vector<unordered_set<int>> adjLists(n);
    for (const auto& edge : edges) {
      adjLists[edge[0]].insert(edge[1]);
      adjLists[edge[1]].insert(edge[0]);
    }
    vector<pair<int, int>> index_pairs;
    index_pairs.reserve(n);
    deque<int> leaves;
    for (int i = 0; i < n; ++i) {
      if (adjLists[i].size() == 1) {
        leaves.push_back(i);
      }
    }
    while (!leaves.empty()) {
      const int index = leaves.front();
      leaves.pop_front();
      const auto it = adjLists[index].begin();
      if (it == adjLists[index].end()) {
        break;
      }
      const int parent_index = *it;
      adjLists[index].erase(it);
      adjLists[parent_index].erase(index);
      index_pairs.emplace_back(index, parent_index);
      if (adjLists[parent_index].size() == 1) {
        leaves.push_back(parent_index);
      }
    }
    vector<int> sums(n);
    for (int groups = n; groups > 1; --groups) {
      if (sum % groups == 0) {
        const long long target = sum / groups;
        sums = nums;
        bool flag = true;
        for (const auto [index, parent_index] : index_pairs) {
          if (sums[index] > target) {
            flag = false;
            break;
          }
          if (sums[index] < target) {
            sums[parent_index] += sums[index];
          }
        }
        if (flag && sums[index_pairs.back().second] == target) {
          return groups - 1;
        }
      }
    }
    return 0;
  }
};
