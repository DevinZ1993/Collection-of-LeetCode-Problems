class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    vector<string> results;
    long long val = 0;
    string result;
    for (int i = 0; i < num.size(); ++i) {
      if (i > 0 && val == 0) {
        break;
      }
      val = 10 * val + (num[i] - '0');
      result.push_back(num[i]);
      solve(num, i + 1, 0, val, target, results, result);
    }
    return results;
  }

 private:
  static constexpr array<char, 3> kOperators = {'+', '-', '*'};

  void solve(const string &num, int index, long long sum, long long product,
             long long target, vector<string> &results, string &result) {
    if (index == num.size()) {
      if (sum + product == target) {
        results.push_back(result);
      }
      return;
    }
    long long val = 0;
    const int start_index = index;
    const int op_index = result.size();
    result.push_back(' ');
    for (; index < num.size(); ++index) {
      if (index > start_index && val == 0) {
        break;
      }
      val = 10 * val + (num[index] - '0');
      result.push_back(num[index]);
      for (char op : kOperators) {
        result[op_index] = op;
        if (op == '+') {
          solve(num, index + 1, sum + product, val, target, results, result);
        } else if (op == '-') {
          solve(num, index + 1, sum + product, -val, target, results, result);
        } else {
          solve(num, index + 1, sum, product * val, target, results, result);
        }
      }
    }
    result.resize(op_index);
  }
};
