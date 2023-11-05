class Solution {
public:
  int stoneGameII(vector<int> &piles) {
    const int n = piles.size();
    vector<vector<vector<int>>> memo(
        n, vector<vector<int>>(n, vector<int>(2, -1)));
    return solve(memo, piles, 0, min(2, n), 0);
  }

private:
  int solve(vector<vector<vector<int>>> &memo, const vector<int> &piles,
            int index, int n_piles, int player) {
    const int n = piles.size();
    if (index == n) {
      return 0;
    }
    int &val = memo[index][n_piles - 1][player];
    if (val < 0) {
      val = (player == 0 ? 0 : INT_MAX);
      int sum = 0;
      for (int p = 1; p <= n_piles && index + p <= n; ++p) {
        sum += piles[index + p - 1];
        const int next_val = solve(memo, piles, index + p,
                                   min(n, max(n_piles, 2 * p)), 1 - player);
        if (player == 0) {
          val = max(val, sum + next_val);
        } else {
          val = min(val, next_val);
        }
      }
    }
    return val;
  }
};
