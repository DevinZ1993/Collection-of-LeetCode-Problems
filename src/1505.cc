class Solution {
 public:
  string minInteger(string num, int k) {
    array<vector<int>, 10> indices;
    const int n = num.size();
    for (int i = n - 1; i >= 0; --i) {
      indices[num[i] - '0'].push_back(i);
    }

    vector<int> fenwick(n + 1);
    const auto query = [&fenwick](int i) {
      ++i;
      int result = 0;
      for (; i > 0; i &= (i - 1)) {
        result += fenwick[i];
      }
      return result;
    };

    string result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
      int digit = 0;
      for (; digit < indices.size(); ++digit) {
        if (!indices[digit].empty() && indices[digit].back() + query(n - 1) -
                                               query(indices[digit].back()) <=
                                           i + k) {
          break;
        }
      }
      assert(digit < indices.size());
      result.push_back('0' + digit);
      const int index =
          indices[digit].back() + query(n - 1) - query(indices[digit].back());
      k -= (index - i);
      for (int j = indices[digit].back() + 1; j < fenwick.size();
           j += (j & (-j))) {
        ++fenwick[j];
      }
      indices[digit].pop_back();
    }
    return result;
  }
};
