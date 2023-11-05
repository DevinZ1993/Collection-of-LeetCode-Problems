class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> results;
    results.reserve(n);
    results.push_back(1);
    vector<int> indices(primes.size(), 0);
    priority_queue<pair<long long, int>> q;
    for (int i = 0; i < primes.size(); ++i) {
      q.emplace(-primes[i], i);
    }
    while (results.size() < n) {
      auto [neg_val, index] = q.top();
      q.pop();
      if (-neg_val > results.back()) {
        results.push_back(-neg_val);
      }
      indices[index] = static_cast<int>(distance(
          results.begin(), lower_bound(results.begin(), results.end(),
                                       1 + results.back() / primes[index])));
      assert(indices[index] < results.size());
      q.emplace(-1LL * primes[index] * results[indices[index]], index);
    }
    return results.back();
  }
};
