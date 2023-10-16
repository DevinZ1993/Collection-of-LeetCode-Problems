class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> results(n - k + 1);
    deque<int> q;
    for (int i = 0; i < n; ++i) {
      if (!q.empty() && q.front() + k - 1 < i) {
        q.pop_front();
      }
      while (!q.empty() && nums[q.back()] < nums[i]) {
        q.pop_back();
      }
      q.push_back(i);
      if (i >= k - 1) {
        results[i - k + 1] = nums[q.front()];
      }
    }
    return results;
  }
};
