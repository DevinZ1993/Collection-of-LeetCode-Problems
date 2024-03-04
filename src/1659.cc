template <size_t N, typename T>
struct NdVector : public vector<NdVector<N - 1, T>> {
  template <typename... Args>
  explicit NdVector(int size, Args... args)
      : vector<NdVector<N - 1, T>>(size, NdVector<N - 1, T>(args...)) {}
};

template <typename T>
struct NdVector<1, T> : public vector<T> {
  explicit NdVector(int size, T init_value) : vector<T>(size, init_value) {}
};

class Solution {
 public:
  int getMaxGridHappiness(int m, int n, int introvertsCount,
                          int extrovertsCount) {
    Memo memo(m, n, introvertsCount + 1, extrovertsCount + 1, 1 << n, 1 << n,
              -1);
    return solve(memo, m, n, 0, 0, introvertsCount, extrovertsCount, 0, 0);
  }

 private:
  using Memo = NdVector<6, int>;

  int solve(Memo &memo, int m, int n, int i, int j, int introverts,
            int extroverts, int i_mask, int e_mask) {
    if (j == n) {
      ++i;
      j = 0;
    }
    if (i == m) {
      return 0;
    }
    int &result = memo[i][j][introverts][extroverts][i_mask][e_mask];
    if (result < 0) {
      result = solve(memo, m, n, i, j + 1, introverts, extroverts,
                     i_mask & ~(1 << j), e_mask & ~(1 << j));
      int score = 0;
      int neighbors = 0;
      if (((i_mask | e_mask) & (1 << j)) != 0) {
        ++neighbors;
        if ((i_mask & (1 << j)) != 0) {
          score -= 30;
        } else {
          score += 20;
        }
      }
      if (j > 0 && ((i_mask | e_mask) & (1 << (j - 1))) != 0) {
        ++neighbors;
        if ((i_mask & (1 << (j - 1))) != 0) {
          score -= 30;
        } else {
          score += 20;
        }
      }
      if (introverts > 0) {
        result = max(result,
                     score + 120 - 30 * neighbors +
                         solve(memo, m, n, i, j + 1, introverts - 1, extroverts,
                               i_mask | (1 << j), e_mask & ~(1 << j)));
      }
      if (extroverts > 0) {
        result = max(result,
                     score + 40 + 20 * neighbors +
                         solve(memo, m, n, i, j + 1, introverts, extroverts - 1,
                               i_mask & ~(1 << j), e_mask | (1 << j)));
      }
    }
    return result;
  }
};
