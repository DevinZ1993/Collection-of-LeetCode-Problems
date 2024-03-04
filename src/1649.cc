class Solution {
 public:
  int createSortedArray(vector<int>& instructions) {
    array<int, 100'002> fenwick{};

    const auto query = [&fenwick](int i) {
      ++i;
      int result = 0;
      for (; i > 0; i &= (i - 1)) {
        result += fenwick[i];
      }
      return result;
    };
    constexpr int mod = 1'000'000'007;
    int result = 0;
    for (int i = 0; i < instructions.size(); ++i) {
      int cost = min(query(instructions[i] - 1), i - query(instructions[i]));
      result = (result + cost) % mod;
      for (int j = instructions[i] + 1; j < fenwick.size(); j += (j & (-j))) {
        ++fenwick[j];
      }
    }
    return result;
  }
};
