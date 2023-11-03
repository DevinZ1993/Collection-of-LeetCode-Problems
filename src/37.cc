class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    const int m = board.size();
    const int n = board[0].size();
    array<int, 9> rows{};
    array<int, 9> cols{};
    array<int, 9> subs{};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == '.') {
          continue;
        }
        const int bit = (1 << (board[i][j] - '0'));
        rows[i] |= bit;
        cols[j] |= bit;
        subs[i / 3 * 3 + j / 3] |= bit;
      }
    }
    vector<tuple<int, int, int>> stk;
    stk.emplace_back(0, 0, 0);
    while (!stk.empty()) {
      const auto [i, j, state] = stk.back();
      stk.pop_back();
      if (state == 0) {
        if (i == 9) {
          break;
        } else if (board[i][j] == '.') {
          for (int val = 1; val <= 9; ++val) {
            if (!(rows[i] & (1 << val)) && !(cols[j] & (1 << val)) &&
                !(subs[i / 3 * 3 + j / 3] & (1 << val))) {
              stk.emplace_back(i, j, val);
            }
          }
        } else if (j == 8) {
          stk.emplace_back(i + 1, 0, 0);
        } else {
          stk.emplace_back(i, j + 1, 0);
        }
        continue;
      }
      if (state < 0) {
        const int bit = (1 << (board[i][j] - '0'));
        rows[i] &= ~bit;
        cols[j] &= ~bit;
        subs[i / 3 * 3 + j / 3] &= ~bit;
        board[i][j] = '.';
        continue;
      }
      stk.emplace_back(i, j, -1);
      rows[i] |= (1 << state);
      cols[j] |= (1 << state);
      subs[i / 3 * 3 + j / 3] |= (1 << state);
      board[i][j] = static_cast<char>('0' + state);
      if (j == 8) {
        stk.emplace_back(i + 1, 0, 0);
      } else {
        stk.emplace_back(i, j + 1, 0);
      }
    }
  }
};
