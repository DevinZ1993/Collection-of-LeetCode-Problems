class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> lines;
    for (int i = 0; i < words.size();) {
      int len = words[i].size();
      int j = i + 1;
      while (j < words.size() && len + 1 + words[j].size() <= maxWidth) {
        len += 1 + words[j].size();
        ++j;
      }
      const int slots = j - i - 1;
      const int extra = maxWidth - len;
      string& line = lines.emplace_back();
      line.reserve(maxWidth);
      line.append(words[i]);
      if (j == words.size()) {
        for (int k = i + 1; k < j; ++k) {
          line.push_back(' ');
          line.append(words[k]);
        }
      } else {
        for (int k = i + 1; k < j; ++k) {
          // Note that (a + b) / b is not necessarily equal to a / b + 1
          // since a might be negative.
          int spaces = (extra + i - k + slots) / slots + 1;
          while (spaces > 0) {
            line.push_back(' ');
            --spaces;
          }
          line.append(words[k]);
        }
      }
      while (line.size() < maxWidth) {
        line.push_back(' ');
      }
      i = j;
    }
    return lines;
  }
};
