class Solution {
 public:
  vector<int> waysToFillArray(vector<vector<int>>& queries) {
    array<int, 10'001> factors{};
    factors[1] = 1;
    for (int i = 2; i < factors.size(); ++i) {
      if (factors[i] > 0) {
        continue;
      }
      factors[i] = i;
      for (int j = 2 * i; j < factors.size(); j += i) {
        factors[j] = i;
      }
    }
    constexpr long long mod = 1'000'000'007LL;
    vector<vector<int>> combs(20'000, vector<int>(16));
    for (int n = 0; n < combs.size(); ++n) {
      combs[n][0] = 1;
      for (int k = 1; k <= n && k < combs[n].size(); ++k) {
        combs[n][k] = (combs[n - 1][k - 1] + combs[n - 1][k]) % mod;
      }
    }
    vector<int> results(queries.size(), 1);
    unordered_map<int, int> cnts;
    for (int index = 0; index < results.size(); ++index) {
      const int n = queries[index][0];
      const int k = queries[index][1];
      cnts.clear();
      for (int num = k; num > 1; num /= factors[num]) {
        ++cnts[factors[num]];
      }
      for (const auto [_, cnt] : cnts) {
        results[index] = static_cast<int>(1LL * results[index] *
                                          combs[n - 1 + cnt][cnt] % mod);
      }
    }
    return results;
  }
};
