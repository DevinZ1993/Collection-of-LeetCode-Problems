class Solution {
 public:
  bool gcdSort(vector<int> &nums) {
    const int n = nums.size();
    unordered_map<int, vector<int>> index_map;
    for (int i = 0; i < n; ++i) {
      index_map[nums[i]].push_back(i);
    }
    array<bool, 100'001> non_primes{};
    vector<int> roots(n, -1);
    for (int i = 2; i < non_primes.size(); ++i) {
      if (non_primes[i]) {
        continue;
      }
      int first = -1;
      for (int j = i; j < non_primes.size(); j += i) {
        non_primes[j] = true;
        if (auto it = index_map.find(j); it != index_map.end()) {
          if (first < 0) {
            first = it->second.front();
          }
          for (int index : it->second) {
            unionByRank(roots, first, index);
          }
        }
      }
    }

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(),
         [&nums](int i, int j) { return nums[i] < nums[j]; });
    vector<bool> vis(n, false);
    for (int start_index = 0; start_index < n; ++start_index) {
      if (vis[start_index]) {
        continue;
      }
      int root = getRoot(roots, start_index);
      for (int i = start_index; !vis[i]; i = indices[i]) {
        vis[i] = true;
        if (root != getRoot(roots, i)) {
          return false;
        }
      }
    }
    return true;
  }

 private:
  void unionByRank(vector<int> &roots, int i, int j) {
    i = getRoot(roots, i);
    j = getRoot(roots, j);
    if (i == j) {
      return;
    }
    if (roots[i] > roots[j]) {
      swap(i, j);
    }
    roots[i] += roots[j];
    roots[j] = i;
  }
  int getRoot(vector<int> &roots, int i) {
    if (roots[i] < 0) {
      return i;
    }
    return roots[i] = getRoot(roots, roots[i]);
  }
};
