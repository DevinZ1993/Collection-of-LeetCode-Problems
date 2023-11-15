/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
 public:
  void findSecretWord(vector<string>& words, Master& master) {
    const int n = words.size();
    vector<vector<int>> matches(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      matches[i][i] = words[i].size();
      for (int j = i + 1; j < n; ++j) {
        int match = 0;
        for (int k = 0; k < words[i].size(); ++k) {
          if (words[i][k] == words[j][k]) {
            ++match;
          }
        }
        matches[i][j] = matches[j][i] = match;
      }
    }
    unordered_map<int, int> counts;
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);

    const auto eval = [&indices, &matches, &counts](int index) {
      counts.clear();
      for (int other : indices) {
        ++counts[matches[index][other]];
      }
      int value = 0;
      for (const auto [_, count] : counts) {
        value = max(value, count);
      }
      return value;
    };

    vector<int> next_indices;
    next_indices.reserve(n);
    while (true) {
      int selected_index = indices[0];
      int min_value = eval(indices[0]);
      for (int i = 1; i < indices.size(); ++i) {
        const int index = indices[i];
        const int value = eval(index);
        if (value < min_value) {
          selected_index = index;
          min_value = value;
        }
      }
      const int result = master.guess(words[selected_index]);
      if (result == words[selected_index].size()) {
        break;
      }
      next_indices.clear();
      for (int other : indices) {
        if (matches[selected_index][other] == result) {
          next_indices.push_back(other);
        }
      }
      swap(indices, next_indices);
    }
  }
};
