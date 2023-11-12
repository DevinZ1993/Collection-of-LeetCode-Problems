class Solution {
 public:
  string minWindow(string s1, string s2) {
    const int m = s2.size();
    vector<int> heads(m, -1);
    int min_length = INT_MAX;
    int index = -1;
    for (int i = 0; i < s1.size(); ++i) {
      for (int j = m - 1; j > 0; --j) {
        if (s1[i] == s2[j]) {
          heads[j] = heads[j - 1];
        }
      }
      if (s1[i] == s2[0]) {
        heads[0] = i;
      }
      if (heads[m - 1] >= 0 && min_length > i - heads[m - 1] + 1) {
        min_length = i - heads[m - 1] + 1;
        index = heads[m - 1];
      }
    }
    return index < 0 ? string{} : s1.substr(index, min_length);
  }
};
