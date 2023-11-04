class Solution {
 public:
  string multiply(string num1, string num2) {
    string result;
    result.resize(num1.size() + num2.size(), '0');
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    for (int i = 0; i < num1.size(); ++i) {
      int cin = 0;
      for (int j = 0; j < num2.size(); ++j) {
        int val =
            (result[i + j] - '0') + (num1[i] - '0') * (num2[j] - '0') + cin;
        result[i + j] = static_cast<char>('0' + val % 10);
        cin = val / 10;
      }
      for (int index = i + num2.size(); cin > 0; ++index) {
        assert(index < result.size());
        int val = (result[index] - '0') + cin;
        result[index] = static_cast<char>('0' + val % 10);
        cin = val / 10;
      }
    }
    while (result.size() > 1 && result.back() == '0') {
      result.pop_back();
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
