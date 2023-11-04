class Solution {
 public:
  vector<int> recoverArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    const int min_val = nums[0];
    unordered_map<int, vector<int>> indices;
    vector<bool> vis(nums.size());
    vector<int> results;
    results.reserve(nums.size() / 2);
    for (int num : nums) {
      if (num == min_val || (num - min_val) % 2 != 0) {
        continue;
      }
      const int delta = num - min_val;
      results.clear();
      fill(vis.begin(), vis.end(), false);
      indices.clear();
      for (int i = 0; i < nums.size(); ++i) {
        indices[nums[i]].push_back(i);
      }
      bool success = true;
      for (int i = 0; i < nums.size() && results.size() * 2 < nums.size();
           ++i) {
        if (vis[i]) {
          continue;
        }
        auto it = indices.find(nums[i] + delta);
        if (it == indices.end()) {
          success = false;
          break;
        }
        const int j = it->second.back();
        vis[j] = true;
        it->second.pop_back();
        if (it->second.empty()) {
          indices.erase(it);
        }
        results.push_back(nums[i] + delta / 2);
      }
      if (success) {
        break;
      }
    }
    return results;
  }
};

// Another solution using std::multiset.
class Solution {
 public:
  vector<int> recoverArray(vector<int>& nums) {
    const int min_val = *min_element(nums.begin(), nums.end());
    multiset<int> tree;
    vector<int> results;
    results.reserve(nums.size() / 2);
    for (int num : nums) {
      if (num == min_val || (num - min_val) % 2 != 0) {
        continue;
      }
      const int delta = num - min_val;
      tree.clear();
      for (int i = 0; i < nums.size(); ++i) {
        tree.insert(nums[i]);
      }
      results.clear();
      bool success = true;
      while (!tree.empty()) {
        auto min_it = tree.begin();
        auto peer_it = tree.find(*min_it + delta);
        if (peer_it == tree.end()) {
          success = false;
          break;
        }
        results.push_back(*min_it + delta / 2);
        tree.erase(min_it);
        tree.erase(peer_it);
      }
      if (success) {
        break;
      }
    }
    return results;
  }
};
