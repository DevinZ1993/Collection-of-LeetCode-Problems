class Solution {
 public:
  vector<int> findSubstring(string s, vector<string> &words) {
    const auto get_cnt = [](const unordered_map<string, int> &cnts,
                            const string &word) {
      auto it = cnts.find(word);
      return it == cnts.end() ? 0 : it->second;
    };

    unordered_map<string, int> cnts;
    for (const string &word : words) {
      ++cnts[word];
    }

    const int word_length = words[0].size();
    unordered_map<string, int> running_cnts;
    vector<int> results;
    for (int start_index = 0; start_index < word_length; ++start_index) {
      running_cnts.clear();
      for (int i = start_index, j = start_index; j < s.size();
           j += word_length) {
        const string sub = s.substr(j, word_length);
        ++running_cnts[sub];
        while (get_cnt(running_cnts, sub) > get_cnt(cnts, sub)) {
          auto it = running_cnts.find(s.substr(i, word_length));
          assert(it != running_cnts.end());
          if (--it->second == 0) {
            running_cnts.erase(it);
          }
          i += word_length;
        }
        if (j == i + word_length * (words.size() - 1)) {
          results.push_back(i);
        }
      }
    }
    return results;
  }
};
