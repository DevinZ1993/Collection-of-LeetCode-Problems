class Solution {
 public:
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    vector<int> i_indices = findIndices(s, a);
    vector<int> j_indices = findIndices(s, b);
    vector<int> results;
    for (int i = 0, min_j = 0, max_j = 0; i < i_indices.size(); ++i) {
      while (min_j < j_indices.size() && j_indices[min_j] + k < i_indices[i]) {
        ++min_j;
      }
      max_j = max(max_j, min_j);
      while (max_j < j_indices.size() && j_indices[max_j] <= i_indices[i] + k) {
        ++max_j;
      }
      if (min_j < max_j) {
        results.push_back(i_indices[i]);
      }
    }
    return results;
  }

 private:
  vector<int> findIndices(const string &s, const string &p) const {
    if (s.size() < p.size()) {
      return {};
    }
    string concatenated;
    concatenated.reserve(s.size() + 1 + p.size());
    concatenated.assign(p.begin(), p.end());
    concatenated.push_back(';');
    concatenated.append(s);
    vector<int> kmp(concatenated.size());
    vector<int> results;
    results.reserve(s.size() - p.size() + 1);
    for (int i = 1; i < concatenated.size(); ++i) {
      int j = kmp[i - 1];
      while (j > 0 && concatenated[j] != concatenated[i]) {
        j = kmp[j - 1];
      }
      if (concatenated[j] == concatenated[i]) {
        ++j;
      }
      kmp[i] = j;
      if (i > p.size() && kmp[i] == p.size()) {
        results.push_back(i - 2 * p.size());
      }
    }
    return results;
  }
};
