class Solution {
 public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    vector<int> forwards(s2.size());
    for (int i = 0; i < s2.size(); ++i) {
      int &forward = forwards[i];
      for (int j = 0; j < s1.size(); ++j) {
        if (s1[j] == s2[(forward + i) % s2.size()]) {
          ++forward;
        }
      }
    }
    int length = 0;
    for (int i = 0; i < n1; ++i) {
      length += forwards[length % s2.size()];
    }
    return length / s2.size() / n2;
  }
};
