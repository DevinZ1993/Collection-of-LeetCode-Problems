class Solution {
 public:
  int minDays(int n) {
    unordered_map<int, int> memo;
    return solve(n, memo);
  }

 private:
  int solve(int n, unordered_map<int, int> &memo) {
    if (n == 0) {
      return 0;
    }
    auto it = memo.find(n);
    if (it == memo.end()) {
      it = memo.emplace(n, min({n, n % 2 + 1 + solve(n / 2, memo),
                                n % 3 + 1 + solve(n / 3, memo)}))
               .first;
    }
    return it->second;
  }
};
