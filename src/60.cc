class Solution {
 public:
  string getPermutation(int n, int k) {
    vector<long long> facts(n + 1, 1LL);
    for (int i = 1; i <= n; ++i) {
      facts[i] = i * facts[i - 1];
    }
    string result;
    result.reserve(n);
    int state = 0;
    for (int i = 0; i < n; ++i) {
      const int index = (k - 1) / facts[n - i - 1];
      for (int j = 0, cnt = 0; j < n; ++j) {
        if ((state & (1 << j)) != 0) {
          continue;
        }
        if (cnt == index) {
          state |= (1 << j);
          result.push_back(static_cast<char>('1' + j));
          break;
        }
        ++cnt;
      }
      k -= index * facts[n - i - 1];
    }
    return result;
  }
};
