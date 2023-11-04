class Solution {
 public:
  vector<string> removeComments(vector<string>& source) {
    vector<string> results;
    string result;
    const auto maybe_append_result = [&result, &results]() {
      if (!result.empty()) {
        results.push_back(move(result));
        result.clear();
      }
    };
    for (int i = 0, j = 0, state = 0; i < source.size();) {
      if (state == 0) {
        size_t line_comment_index = source[i].find("//", j);
        size_t block_comment_index = source[i].find("/*", j);
        if (line_comment_index < block_comment_index) {
          result.append(source[i].substr(j, line_comment_index - j));
          maybe_append_result();
          ++i;
          j = 0;
          continue;
        }
        if (block_comment_index < line_comment_index) {
          result.append(source[i].substr(j, block_comment_index - j));
          j = block_comment_index + 2;
          state = 1;
          continue;
        }
        result.append(source[i].substr(j));
        maybe_append_result();
        ++i;
        j = 0;
        continue;
      }
      size_t end_index = source[i].find("*/", j);
      if (end_index == string::npos) {
        ++i;
        j = 0;
      } else {
        j = end_index + 2;
        state = 0;
      }
    }
    assert(result.empty());
    return results;
  }
};
