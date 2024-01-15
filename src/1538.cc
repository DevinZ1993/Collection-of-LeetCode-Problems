/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has
 * value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements
 * have a value equal to 1. int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class ReaderWrapper {
 public:
  explicit ReaderWrapper(ArrayReader *reader) : reader_(*reader) {}

  int Get(int a, int b, int c, int d) {
    array<int, 4> indices = {a, b, c, d};
    sort(indices.begin(), indices.end());
    string key;
    for (int index : indices) {
      key.append(to_string(index));
      key.push_back(',');
    }
    auto it = memo_.find(key);
    if (it == memo_.end()) {
      const int result =
          reader_.query(indices[0], indices[1], indices[2], indices[3]);
      it = memo_.insert({key, result}).first;
    }
    return it->second;
  }

 private:
  ArrayReader &reader_;
  unordered_map<string, int> memo_;
};

class Solution {
 public:
  int guessMajority(ArrayReader &reader) {
    ReaderWrapper wrapper(&reader);
    const int n = reader.length();
    const array<int, 5> head = QueryHead(wrapper);
    int diff_index = -1;
    for (int i = 1; i < head.size(); ++i) {
      if (head[i] != head[0]) {
        diff_index = i;
        break;
      }
    }
    int same = 1;
    for (int i = 1; i <= 2; ++i) {
      if (head[i] == head[0]) {
        ++same;
      }
    }
    int same_result = -1;
    if (same == 3) {
      same_result = 4;
    } else if (same == 2) {
      same_result = 2;
    } else {
      same_result = 0;
    }
    for (int i = 3; i < n; ++i) {
      if (wrapper.Get(0, 1, 2, i) == same_result) {
        ++same;
      } else if (diff_index < 0) {
        diff_index = i;
      }
    }
    if (2 * same == n) {
      return -1;
    }
    return 2 * same > n ? 0 : diff_index;
  }

 private:
  array<int, 5> QueryHead(ReaderWrapper &wrapper) {
    array<int, 5> query_results;
    for (int i = 0; i < query_results.size(); ++i) {
      query_results[i] =
          wrapper.Get((i + 1) % 5, (i + 2) % 5, (i + 3) % 5, (i + 4) % 5);
    }
    if (all_of(query_results.begin(), query_results.end(),
               [](int x) { return x == 4; })) {
      return array<int, 5>{};
    }
    if (auto it = find(query_results.begin(), query_results.end(), 4);
        it != query_results.end()) {
      const int index = distance(query_results.begin(), it);
      array<int, 5> results{};
      results[index] = 1;
      return results;
    }
    auto it = find(query_results.begin(), query_results.end(), 0);
    assert(it != query_results.end());
    const int index = distance(query_results.begin(), it);
    array<int, 5> results;
    for (int i = 0; i < results.size(); ++i) {
      if (i == index) {
        results[i] = 0;
      } else if (query_results[i] == 2) {
        results[i] = 1;
      } else {
        results[i] = 0;
      }
    }
    return results;
  }
};
