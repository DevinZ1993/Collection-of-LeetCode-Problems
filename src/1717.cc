class Solution {
 public:
  int maximumGain(string s, int x, int y) {
    char a = 'a';
    char b = 'b';
    if (x < y) {
      swap(a, b);
      swap(x, y);
    }
    int result = 0;
    string stk;
    for (char ch : s) {
      if (!stk.empty() && stk.back() == a && ch == b) {
        stk.pop_back();
        result += x;
        continue;
      }
      stk.push_back(ch);
    }
    swap(stk, s);
    stk.clear();
    for (char ch : s) {
      if (!stk.empty() && stk.back() == b && ch == a) {
        stk.pop_back();
        result += y;
        continue;
      }
      stk.push_back(ch);
    }
    return result;
  }
};
