class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> results;
    for (int i = 0; i < words.size();) {
      int length = words[i].size();
      int j = i + 1;
      for (; j < words.size(); ++j) {
        if (length + 1 + words[j].size() > maxWidth) {
          break;
        }
        length += 1 + words[j].size();
      }
      string& result = results.emplace_back();
      result.reserve(maxWidth);
      result.append(words[i]);
      const int total_spaces = maxWidth - length + (j - i - 1);
      for (int k = i + 1, kk = j - i - 2; k < j; ++k, --kk) {
        int spaces =
            (j == words.size() ? 1 : (total_spaces + kk) / (j - i - 1));
        while (--spaces >= 0) {
          result.push_back(' ');
        }
        result.append(words[k]);
      }
      while (result.size() < maxWidth) {
        result.push_back(' ');
      }
      i = j;
    }
    return results;
  }
};
