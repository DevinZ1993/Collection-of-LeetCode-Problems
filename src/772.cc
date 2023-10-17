class Solution {
 public:
  struct State {
    long long sum = 0;
    long long prod = 0;
    char last_op = '+';

    long long eval() const { return sum + prod; }

    void consume_operand(long long val) {
      if (last_op == '+') {
        sum += prod;
        prod = val;
      } else if (last_op == '-') {
        sum += prod;
        prod = -val;
      } else if (last_op == '*') {
        prod *= val;
      } else if (last_op == '/') {
        prod /= val;
      }
    }
  };

  int calculate(string s) {
    vector<State> stk;
    stk.emplace_back();
    long long val = 0;
    for (int i = 0, j = 0; j <= s.size(); ++j) {
      if (j == s.size() || s[j] < '0' || s[j] > '9') {
        if (i < j) {
          stk.back().consume_operand(val);
        }
        if (j < s.size()) {
          if (s[j] == '(') {
            stk.emplace_back();
          } else if (s[j] == ')') {
            val = stk.back().eval();
            stk.pop_back();
            stk.back().consume_operand(val);
          } else if (s[j] != ' ') {
            stk.back().last_op = s[j];
          }
        }
        val = 0;
        i = j + 1;
      } else {
        val = 10 * val + (s[j] - '0');
      }
    }
    assert(stk.size() == 1);
    return stk.back().eval();
  }
};
