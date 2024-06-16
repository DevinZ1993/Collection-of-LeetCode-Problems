class Solution {
 public:
  vector<string> removeComments(vector<string> &source) {
    vector<string> results;
    string line;
    const auto append_line = [&results, &line]() {
      if (!line.empty()) {
        results.push_back(line);
        line.clear();
      }
    };
    for (int i = 0, j = 0, state = 0; i < source.size();) {
      if (state == 0) {
        const int single = find(source[i], j, "//");
        const int multi = find(source[i], j, "/*");
        if (single < multi) {
          line.append(source[i].substr(j, single - j));
          append_line();
          ++i;
          j = 0;
          continue;
        }
        if (multi < single) {
          line.append(source[i].substr(j, multi - j));
          j = multi + 2;
          state = 1;
          continue;
        }
        line.append(source[i].substr(j));
        append_line();
        ++i;
        j = 0;
      } else {
        const int end = find(source[i], j, "*/");
        if (end == source[i].size()) {
          ++i;
          j = 0;
          continue;
        }
        j = end + 2;
        state = 0;
      }
    }
    append_line();
    return results;
  }

 private:
  int find(const string &s, int i, const string &p) {
    size_t idx = s.find(p, i);
    if (idx == string::npos) {
      return s.size();
    }
    return idx;
  }
};
