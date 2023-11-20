class Solution {
 public:
  vector<int> findArray(vector<int>& pref) {
    vector<int> results(pref);
    for (int i = 1; i < results.size(); ++i) {
      results[i] ^= pref[i - 1];
    }
    return results;
  }
};
