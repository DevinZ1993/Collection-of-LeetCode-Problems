class Solution {
 public:
  bool canTransform(string start, string end) {
    int i = 0;
    int j = 0;
    while (i < start.size() && j < end.size()) {
      if (start[i] == 'X') {
        ++i;
        continue;
      }
      if (end[j] == 'X') {
        ++j;
        continue;
      }
      if (start[i] != end[j]) {
        return false;
      }
      if (start[i] == 'L' && i < j) {
        return false;
      }
      if (end[j] == 'R' && i > j) {
        return false;
      }
      ++i;
      ++j;
    }
    return all_of(start.begin() + i, start.end(),
                  [](char ch) { return ch == 'X'; }) &&
           all_of(end.begin() + j, end.end(),
                  [](char ch) { return ch == 'X'; });
  }
};
