class Solution {
 public:
  int minOperationsToFlip(string expression) {
    struct State {
      int zero = 0;
      int one = 0;
      char last_op = '\0';
    };
    vector<State> states(1);
    const auto apply_val = [&states](int new_zero, int new_one) {
      assert(!states.empty());
      State &state = states.back();
      if (state.last_op == '\0') {
        state.zero = new_zero;
        state.one = new_one;
        return;
      }
      int next_zero, next_one;
      if (state.last_op == '&') {
        next_zero = min({state.zero, new_zero, state.zero + new_zero + 1});
        next_one = min({state.one + new_one, min(state.one, new_one) + 1});
      } else {
        next_zero = min({state.zero + new_zero, min(state.zero, new_zero) + 1});
        next_one = min({state.one, new_one, state.one + new_one + 1});
      }
      state.zero = next_zero;
      state.one = next_one;
    };
    for (char ch : expression) {
      if (ch == '(') {
        states.emplace_back();
      } else if (ch == ')') {
        int new_zero = states.back().zero;
        int new_one = states.back().one;
        states.pop_back();
        apply_val(new_zero, new_one);
      } else if (ch == '|' || ch == '&') {
        states.back().last_op = ch;
      } else if (ch == '0') {
        apply_val(0, 1);
      } else {
        apply_val(1, 0);
      }
    }
    assert(states.size() == 1);
    return max(states.back().zero, states.back().one);
  }
};
