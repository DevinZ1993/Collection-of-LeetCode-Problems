class Solution {
 public:
  int atMostNGivenDigitSet(vector<string>& digit_strings, int n) {
    string digits;
    for (const string& digit_string : digit_strings) {
      digits.push_back(digit_string[0]);
    }
    const string n_digits = to_string(n);
    vector<int> pows(n_digits.size());
    pows[0] = 1;
    for (int i = 1; i < pows.size(); ++i) {
      pows[i] = pows[i - 1] * digits.size();
    }

    int result = 0;
    for (int len = 1; len < n_digits.size(); ++len) {
      result += pows[len];
    }
    bool exited = false;
    for (int i = 0; i < n_digits.size(); ++i) {
      int j = 0;
      for (; j < digits.size(); ++j) {
        if (digits[j] >= n_digits[i]) {
          break;
        }
      }
      result += j * pows[n_digits.size() - i - 1];
      if (j == digits.size() || digits[j] != n_digits[i]) {
        exited = true;
        break;
      }
    }
    if (!exited) {
      ++result;
    }
    return result;
  }
};
