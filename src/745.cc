class WordFilter {
 public:
  WordFilter(vector<string>& words) {
    for (int i = 0; i < words.size(); ++i) {
      string prefix;
      for (char ch : words[i]) {
        prefix.push_back(ch);
        for (int j = 0; j < words[i].size(); ++j) {
          string key;
          key.reserve(prefix.size() + 1 + words[i].size() - j);
          key.append(prefix);
          key.push_back('$');
          key.append(words[i].substr(j));
          indices[key] = i;
        }
      }
    }
  }

  int f(string pref, string suff) {
    string key;
    key.reserve(pref.size() + 1 + suff.size());
    key.append(pref);
    key.push_back('$');
    key.append(suff);
    auto it = indices.find(key);
    if (it == indices.end()) {
      return -1;
    }
    return it->second;
  }

 private:
  unordered_map<string, int> indices;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
