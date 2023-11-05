class Solution {
public:
  struct State {
    int dist = INT_MAX;
    vector<string> prevs;
  };

  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {
    const unordered_set<string> word_set(wordList.begin(), wordList.end());
    unordered_map<string, State> states;
    states[beginWord].dist = 0;
    deque<string> q;
    q.push_back(beginWord);
    while (!q.empty()) {
      const string word = q.front();
      q.pop_front();
      if (word == endWord) {
        break;
      }
      const State &prev_state = states.at(word);
      string next_word(word);
      for (int i = 0; i < next_word.size(); ++i) {
        for (char ch = 'a'; ch <= 'z'; ++ch) {
          if (ch == word[i]) {
            continue;
          }
          next_word[i] = ch;
          if (!word_set.count(next_word)) {
            continue;
          }
          State &state = states[next_word];
          if (state.dist >= prev_state.dist + 1) {
            if (state.dist == INT_MAX) {
              state.dist = prev_state.dist + 1;
              q.push_back(next_word);
            }
            state.prevs.push_back(word);
          }
        }
        next_word[i] = word[i];
      }
    }
    if (!states.count(endWord)) {
      return {};
    }
    vector<vector<string>> paths;
    vector<string> path;
    createPaths(states, endWord, paths, path);
    return paths;
  }

private:
  void createPaths(const unordered_map<string, State> &states,
                   const string &word, vector<vector<string>> &paths,
                   vector<string> &path) {
    path.emplace_back(word);
    const State &state = states.at(word);
    if (state.prevs.empty()) {
      auto &result = paths.emplace_back(path);
      reverse(result.begin(), result.end());
    } else {
      for (const string &prev : state.prevs) {
        createPaths(states, prev, paths, path);
      }
    }
    path.pop_back();
  }
};
