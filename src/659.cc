class Solution {
 public:
  bool isPossible(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    deque<pair<int, priority_queue<int>>> q;
    for (int num : nums) {
      while (!q.empty() && q.front().first + 1 < num) {
        if (!q.front().second.empty() && -q.front().second.top() < 3) {
          return false;
        }
        q.pop_front();
      }
      int length = 1;
      if (!q.empty() && q.front().first + 1 == num) {
        length = -q.front().second.top() + 1;
        q.front().second.pop();
        if (q.front().second.empty()) {
          q.pop_front();
        }
      }
      if (q.empty() || q.back().first < num) {
        q.emplace_back().first = num;
      }
      q.back().second.push(-length);
    }
    return all_of(q.begin(), q.end(),
                  [](const auto& item) { return -item.second.top() >= 3; });
  }
};
