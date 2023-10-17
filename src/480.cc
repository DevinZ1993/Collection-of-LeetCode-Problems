class Solution {
 public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<double> results(n - k + 1);
    multiset<int> smallers;
    multiset<int> largers;
    for (int i = 0; i < n; ++i) {
      if (smallers.empty()) {
        smallers.insert(nums[i]);
      } else {
        const int smaller_max = *smallers.rbegin();
        if (nums[i] <= smaller_max) {
          smallers.insert(nums[i]);
        } else {
          largers.insert(nums[i]);
        }
        if (i >= k) {
          if (nums[i - k] <= smaller_max) {
            smallers.erase(smallers.find(nums[i - k]));
          } else {
            largers.erase(largers.find(nums[i - k]));
          }
        }
        while (smallers.size() > largers.size() + 1) {
          auto it = smallers.rbegin();
          largers.insert(*it);
          smallers.erase(prev(it.base()));
        }
        while (largers.size() > smallers.size()) {
          auto it = largers.begin();
          smallers.insert(*it);
          largers.erase(it);
        }
      }
      if (i < k - 1) {
        continue;
      }
      if (k % 2 == 0) {
        results[i - k + 1] =
            0.5 * (0LL + *smallers.rbegin() + *largers.begin());
      } else {
        results[i - k + 1] = *smallers.rbegin();
      }
    }
    return results;
  }
};
