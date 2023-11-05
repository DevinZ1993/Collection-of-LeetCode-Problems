class Solution {
 public:
  int catMouseGame(vector<vector<int>> &graph) {
    const int n = graph.size();
    struct State {
      // 0 for cat, 1 for mouse
      int winner = -1;
      int outbounds = 0;
    };
    vector<vector<vector<State>>> memo(
        2, vector<vector<State>>(n, vector<State>(n)));
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        memo[0][i][j].outbounds = graph[i].size();
        memo[1][i][j].outbounds = graph[j].size();
      }
    }
    vector<tuple<int, int, int>> stk;
    for (int player = 0; player <= 1; ++player) {
      for (int i = 0; i < n; ++i) {
        memo[player][i][0].winner = 1;
        stk.emplace_back(player, i, 0);
        if (i > 0) {
          memo[player][0][i].winner = 1;
          stk.emplace_back(player, 0, i);
          memo[player][i][i].winner = 0;
          stk.emplace_back(player, i, i);
        }
      }
    }
    while (!stk.empty()) {
      auto [player, i, j] = stk.back();
      stk.pop_back();
      if (player == 1 && i == 2 && j == 1) {
        return 2 - memo[player][i][j].winner;
      }
      const State &state = memo[player][i][j];
      for (int prev_index : graph[player == 0 ? j : i]) {
        const int prev_i = player == 0 ? i : prev_index;
        const int prev_j = player == 1 ? j : prev_index;
        State &prev_state = memo[1 - player][prev_i][prev_j];
        if (prev_state.winner >= 0) {
          continue;
        }
        if (state.winner == 1 - player || --prev_state.outbounds == 0) {
          prev_state.winner = state.winner;
          stk.emplace_back(1 - player, prev_i, prev_j);
        }
      }
    }
    return 0;
  }
};
