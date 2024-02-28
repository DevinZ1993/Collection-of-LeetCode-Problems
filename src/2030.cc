class Solution {
 public:
  string smallestSubsequence(string s, int k, char letter, int repetition) {
    int letter_cnt = 0;
    for (char ch : s) {
      if (ch == letter) {
        ++letter_cnt;
      }
    }
    const int n = s.size();
    int letter_in_result = 0;
    string result;
    for (int i = 0; i < n; ++i) {
      while (!result.empty() && result.back() > s[i] &&
             (result.back() != letter ||
              letter_in_result + letter_cnt > repetition) &&
             result.size() + n - i - 1 >= k) {
        if (result.back() == letter) {
          --letter_in_result;
        }
        result.pop_back();
      }
      if (result.size() < k &&
          (s[i] == letter ||
           result.size() + max(0, repetition - letter_in_result) < k)) {
        result.push_back(s[i]);
        if (s[i] == letter) {
          ++letter_in_result;
        }
      }
      if (s[i] == letter) {
        --letter_cnt;
      }
    }
    return result;
  }
};
