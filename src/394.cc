class Solution {
 public:
  string decodeString(string s) {
    vector<pair<int, string>> stk;
    stk.emplace_back().first = 1;
    for (int i = 0, j = 0, val = 0; j < s.size(); ++j) {
      if (j == s.size() || s[j] < '0' || s[j] > '9') {
        if (i < j) {
          assert(s[j] == '[');
          stk.emplace_back().first = val;
          val = 0;
        } else if (s[j] == ']') {
          auto item = stk.back();
          stk.pop_back();
          assert(!stk.empty());
          while (item.first-- > 0) {
            stk.back().second.append(item.second);
          }
        } else {
          stk.back().second.push_back(s[j]);
        }
        i = j + 1;
      } else {
        val = 10 * val + (s[j] - '0');
      }
    }
    assert(stk.size() == 1);
    return stk.back().second;
  }
};
