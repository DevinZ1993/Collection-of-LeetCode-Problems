class Solution {
 public:
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    vector<int> a_indices = getIndices(s, a);
    vector<int> b_indices = getIndices(s, b);
    vector<int> results;
    for (int i = 0, j = 0; i < a_indices.size() && j < b_indices.size(); ++i) {
      while (j < b_indices.size() && b_indices[j] + k < a_indices[i]) {
        ++j;
      }
      if (j < b_indices.size() && b_indices[j] <= a_indices[i] + k) {
        results.push_back(a_indices[i]);
      }
    }
    return results;
  }

 private:
  vector<int> getIndices(const string &s, const string &p) const {
    vector<int> kmp(p.size());
    for (int i = 1; i < p.size(); ++i) {
      int j = kmp[i - 1];
      while (j > 0 && p[j] != p[i]) {
        j = kmp[j - 1];
      }
      if (p[j] == p[i]) {
        ++j;
      }
      kmp[i] = j;
    }
    vector<int> results;
    for (int i = 0, j = 0; i < s.size(); ++i) {
      while (j > 0 && s[i] != p[j]) {
        j = kmp[j - 1];
      }
      if (s[i] == p[j]) {
        if (++j == p.size()) {
          results.push_back(i - p.size() + 1);
          j = kmp[j - 1];
        }
      }
    }
    return results;
  }
};
