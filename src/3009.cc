/** Line sweep: */
class Solution {
 public:
  int maxIntersectionCount(vector<int>& y) {
    const int n = y.size();
    map<int, vector<int>> tree;
    for (int i = 0; i < n; ++i) {
      tree[y[i]].push_back(i);
    }
    int lines = 0;
    int result = 0;
    for (auto it = tree.begin(); it != tree.end(); ++it) {
      for (int index : it->second) {
        if (index > 0 && y[index - 1] < y[index]) {
          --lines;
        }
        if (index + 1 < n && y[index + 1] < y[index]) {
          --lines;
        }
      }
      result = max<int>(result, it->second.size() + lines);
      for (int index : it->second) {
        if (index > 0 && y[index - 1] > y[index]) {
          ++lines;
        }
        if (index + 1 < n && y[index + 1] > y[index]) {
          ++lines;
        }
      }
      result = max(result, lines);
    }
    return result;
  }
};

/** Difference array: */
class Solution {
 public:
  int maxIntersectionCount(vector<int>& y) {
    vector<int> sorted_vals(y);
    sort(sorted_vals.begin(), sorted_vals.end());
    sorted_vals.erase(unique(sorted_vals.begin(), sorted_vals.end()),
                      sorted_vals.end());
    unordered_map<int, int> indices;
    for (int i = 0; i < sorted_vals.size(); ++i) {
      indices.emplace(sorted_vals[i], i);
    }
    vector<int> cnts(sorted_vals.size());
    for (int y_val : y) {
      ++cnts[indices.at(y_val)];
    }
    vector<int> diffs(sorted_vals.size() * 2);
    for (int i = 0; i + 1 < y.size(); ++i) {
      const int start = indices.at(y[i]);
      const int end = indices.at(y[i + 1]);
      const int min_index = min(start, end);
      const int max_index = max(start, end);
      ++diffs[min_index * 2 + 1];
      --diffs[max_index * 2];
    }
    int result = 0;
    int sum = 0;
    for (int i = 0; i < diffs.size(); ++i) {
      sum += diffs[i];
      result = max(result, sum);
      if (i % 2 == 0) {
        result = max(result, sum + cnts[i / 2]);
      }
    }
    return result;
  }
};
