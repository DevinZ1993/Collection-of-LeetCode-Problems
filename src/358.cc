class Solution {
 public:
  string rearrangeString(string s, int k) {
    array<int, 26> cnts{};
    for (char ch : s) {
      ++cnts[ch - 'a'];
    }
    priority_queue<pair<int, char>> q;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      if (cnts[ch - 'a'] > 0) {
        q.emplace(cnts[ch - 'a'], ch);
      }
    }
    priority_queue<pair<int, char>> wait_list;
    string result;
    result.reserve(s.size());
    while (result.size() < s.size()) {
      const int index = result.size();
      while (!wait_list.empty() && -wait_list.top().first <= index) {
        const char ch = wait_list.top().second;
        wait_list.pop();
        q.emplace(cnts[ch - 'a'], ch);
      }
      if (q.empty()) {
        return {};
      }
      const char ch = q.top().second;
      q.pop();
      result.push_back(ch);
      --cnts[ch - 'a'];
      if (cnts[ch - 'a'] > 0) {
        wait_list.emplace(-index - k, ch);
      }
    }
    return result;
  }
};
