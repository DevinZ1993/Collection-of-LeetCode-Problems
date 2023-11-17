class Solution {
 public:
  int minAddToMakeValid(string s) {
    int result = 0;
    int state = 0;
    for (char ch : s) {
      if (ch == '(') {
        ++state;
        continue;
      }
      if (state > 0) {
        --state;
      } else {
        ++result;
      }
    }
    return result + state;
  }
};
