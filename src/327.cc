class Solution {
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    const int n = nums.size();
    map<long long, int> indices;
    long long sum = 0;
    indices.emplace(sum, 0);
    for (int num : nums) {
      sum += num;
      indices.emplace(sum, 0);
    }
    int n_values = 0;
    for (auto it = indices.begin(); it != indices.end(); ++it) {
      it->second = n_values++;
    }
    vector<int> fenwick(n_values + 1);
    const auto inc = [&fenwick](int index) {
      ++index;
      for (; index < fenwick.size(); index += (index & (-index))) {
        ++fenwick[index];
      }
    };
    const auto query = [&fenwick](int index) {
      int result = 0;
      ++index;
      for (; index > 0; index &= (index - 1)) {
        result += fenwick[index];
      }
      return result;
    };
    sum = 0;
    inc(indices.at(sum));
    int result = 0;
    for (int num : nums) {
      sum += num;
      auto begin_it = indices.lower_bound(sum - upper);
      if (begin_it != indices.end() && begin_it->first <= sum - lower) {
        auto end_it = indices.upper_bound(sum - lower);
        assert(end_it != indices.begin());
        result += query(prev(end_it)->second) - query(begin_it->second - 1);
      }
      inc(indices.at(sum));
    }
    return result;
  }
};
