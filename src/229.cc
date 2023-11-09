class Solution {
 public:
  vector<int> majorityElement(vector<int> &nums) {
    constexpr int k = 3;
    vector<pair<int, int>> cnts;
    cnts.reserve(k - 1);
    for (int num : nums) {
      auto it = find_if(cnts.begin(), cnts.end(),
                        [num](const auto &item) { return item.first == num; });
      if (it != cnts.end()) {
        ++it->second;
        continue;
      }
      if (cnts.size() < k - 1) {
        cnts.emplace_back(num, 1);
        continue;
      }

      it = find_if(cnts.begin(), cnts.end(),
                   [](const auto &item) { return item.second == 0; });
      if (it != cnts.end()) {
        it->first = num;
        it->second = 1;
        continue;
      }
      for_each(cnts.begin(), cnts.end(), [](auto &item) { --item.second; });
    }
    vector<int> results;
    for (auto [key, _] : cnts) {
      if (count(nums.begin(), nums.end(), key) > nums.size() / 3) {
        results.push_back(key);
      }
    }
    return results;
  }
};
