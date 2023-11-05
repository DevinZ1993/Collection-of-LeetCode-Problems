class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> results;
    vector<bool> removed(s.size(), false);
    solve(s, removed, results, 0, 0, true);
    return results;
  }

 private:
  void solve(const string &s, vector<bool> &removed, vector<string> &results,
             int index, int index_to_remove, bool left_to_right) {
    char open = '(';
    char close = ')';
    if (!left_to_right) {
      swap(open, close);
    }
    const int end_index = (left_to_right ? s.size() : -1);
    const int index_delta = (left_to_right ? 1 : -1);
    for (int balance = 0; index != end_index; index += index_delta) {
      if (removed[index]) {
        continue;
      }
      if (s[index] == open) {
        ++balance;
        continue;
      }
      if (s[index] != close) {
        continue;
      }
      if (balance > 0) {
        --balance;
        continue;
      }
      for (int j = index_to_remove; j != index + index_delta;
           j += index_delta) {
        if (s[j] != close ||
            (j != index_to_remove && s[j - index_delta] == close)) {
          continue;
        }
        removed[j] = true;
        solve(s, removed, results, index + index_delta, j + index_delta,
              left_to_right);
        removed[j] = false;
      }
      return;
    }
    if (left_to_right) {
      return solve(s, removed, results, s.size() - 1, s.size() - 1,
                   !left_to_right);
    }
    string &result = results.emplace_back();
    for (int i = 0; i < removed.size(); ++i) {
      if (!removed[i]) {
        result.push_back(s[i]);
      }
    }
  }
};
