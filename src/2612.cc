class Solution {
 public:
  vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
    const unordered_set<int> banned_set(banned.begin(), banned.end());
    vector<int> results(n, -1);
    set<int> odds;
    set<int> evens;
    for (int i = 0; i < n; ++i) {
      if (i == p) {
        continue;
      }
      if (i % 2 == 0) {
        evens.insert(i);
      } else {
        odds.insert(i);
      }
    }
    deque<int> q = {p};
    results[p] = 0;
    while (!q.empty()) {
      const int index = q.front();
      q.pop_front();
      const int min_index = 2 * max(0, index - k + 1) + k - 1 - index;
      const int max_index = 2 * min(n - 1, index + k - 1) - k + 1 - index;
      auto& tree = ((index + k) % 2 == 0) ? odds : evens;
      for (auto it = tree.lower_bound(min_index);
           it != tree.end() && *it <= max_index;) {
        const auto next_it = next(it);
        if (!banned_set.count(*it)) {
          q.push_back(*it);
          results[*it] = results[index] + 1;
        }
        tree.erase(it);
        it = next_it;
      }
    }
    return results;
  }
};
