class Solution {
 public:
  string removeDuplicateLetters(string s) {
    const int n = s.size();
    array<int, 26> last_indices;
    fill(last_indices.begin(), last_indices.end(), -1);
    for (int i = 0; i < n; ++i) {
      last_indices[s[i] - 'a'] = i;
    }
    string result;
    int state = 0;
    for (int i = 0; i < n; ++i) {
      if ((state & (1 << (s[i] - 'a'))) != 0) {
        continue;
      }
      while (!result.empty() && result.back() > s[i] &&
             last_indices[result.back() - 'a'] > i) {
        state &= ~(1 << (result.back() - 'a'));
        result.pop_back();
      }
      state |= (1 << (s[i] - 'a'));
      result.push_back(s[i]);
    }
    return result;
  }
};
