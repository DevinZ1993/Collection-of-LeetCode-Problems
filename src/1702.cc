class Solution {
 public:
  string maximumBinaryString(string binary) {
    deque<int> zeros;
    for (int i = 0; i < binary.size(); ++i) {
      if (binary[i] == '0') {
        zeros.push_back(i);
      }
    }
    string result;
    result.reserve(binary.size());
    for (int i = 0; i < binary.size(); ++i) {
      if (zeros.empty() || i < zeros.front()) {
        result.push_back('1');
        continue;
      }
      zeros.pop_front();
      if (zeros.empty()) {
        result.push_back('0');
        continue;
      }
      zeros.pop_front();
      zeros.push_front(i + 1);
      result.push_back('1');
    }
    return result;
  }
};
