class Solution {
 public:
  int kSimilarity(string s1, string s2) {
    int min_dist = 0;
    array<array<int, 6>, 6> cnts{};
    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] == s2[i]) {
        continue;
      }
      if (cnts[s2[i] - 'a'][s1[i] - 'a'] > 0) {
        --cnts[s2[i] - 'a'][s1[i] - 'a'];
        ++min_dist;
      } else {
        ++cnts[s1[i] - 'a'][s2[i] - 'a'];
      }
    }
    string start;
    string target;
    for (int i = 0; i < cnts.size(); ++i) {
      for (int j = 0; j < cnts[i].size(); ++j) {
        for (int k = 0; k < cnts[i][j]; ++k) {
          start.push_back('a' + i);
          target.push_back('a' + j);
        }
      }
    }
    if (start == target) {
      return min_dist;
    }

    unordered_map<string, int> dists;
    deque<string> q;
    dists.emplace(start, min_dist);
    q.push_back(start);
    while (!q.empty()) {
      string word = q.front();
      q.pop_front();
      const int dist = dists.at(word);
      for (int i = 0; i < word.size(); ++i) {
        if (word[i] != target[i]) {
          for (int j = i + 1; j < word.size(); ++j) {
            if (word[j] != target[j] && word[j] == target[i]) {
              swap(word[i], word[j]);
              if (word == target) {
                return dist + 1;
              }
              if (!dists.count(word)) {
                dists.emplace(word, dist + 1);
                q.push_back(word);
              }
              swap(word[i], word[j]);
            }
          }
          break;
        }
      }
    }
    return -1;
  }
};
