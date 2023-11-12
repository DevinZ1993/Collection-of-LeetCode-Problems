class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> results;
    for (int num : asteroids) {
      if (num > 0) {
        results.push_back(num);
        continue;
      }
      while (!results.empty() && results.back() > 0 && num < 0) {
        const int left = results.back();
        if (left <= -num) {
          results.pop_back();
        }
        if (left >= -num) {
          num = 0;
        }
      }
      if (num < 0) {
        results.push_back(num);
      }
    }
    return results;
  }
};
