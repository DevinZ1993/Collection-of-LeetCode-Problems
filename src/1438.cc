class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    deque<int> min_q;
    deque<int> max_q;
    int result = 0;
    for (int i = 0, j = 0; j < nums.size(); ++j) {
      while (!min_q.empty() && nums[min_q.back()] > nums[j]) {
        min_q.pop_back();
      }
      min_q.push_back(j);
      while (!max_q.empty() && nums[max_q.back()] < nums[j]) {
        max_q.pop_back();
      }
      max_q.push_back(j);
      while (nums[max_q.front()] > nums[min_q.front()] + limit) {
        if (max_q.front() < min_q.front()) {
          i = max(i, max_q.front() + 1);
          max_q.pop_front();
        } else {
          i = max(i, min_q.front() + 1);
          min_q.pop_front();
        }
      }
      result = max(result, j - i + 1);
    }
    return result;
  }
};
