class Solution {
 public:
  int distinctEchoSubstrings(string text) {
    constexpr long long mod = 1'000'000'007LL;
    constexpr long long factor = 26;
    const int n = text.size();
    int result = 0;
    deque<long long> q;
    unordered_map<long long, vector<int>> indices;
    const auto is_substring_visited = [&indices, &text](long long hash, int i,
                                                        int len) {
      auto it = indices.find(hash);
      if (it == indices.end()) {
        return false;
      }
      return find_if(it->second.begin(), it->second.end(),
                     [&text, i, len](int j) {
                       return equal(text.begin() + i, text.begin() + i + len,
                                    text.begin() + j);
                     }) != it->second.end();
    };
    long long pow = 1;
    for (int len = 1; len * 2 <= n; ++len) {
      q.clear();
      indices.clear();
      long long hash = 0;
      for (int i = 0; i < n; ++i) {
        hash = (factor * hash % mod + (text[i] - 'a')) % mod;
        if (q.size() == len) {
          if (q.front() == hash &&
              !is_substring_visited(hash, i + 1 - len, len) &&
              equal(text.begin() + i + 1 - len, text.begin() + i + 1,
                    text.begin() + i + 1 - 2 * len)) {
            indices[hash].push_back(i + 1 - len);
            ++result;
          }
          q.pop_front();
        }
        if (i >= len - 1) {
          q.push_back(hash);
          hash = (hash + mod - pow * (text[i - len + 1] - 'a') % mod) % mod;
        }
      }
      pow = pow * factor % mod;
    }
    return result;
  }
};
