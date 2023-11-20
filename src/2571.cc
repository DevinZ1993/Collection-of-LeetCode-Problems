class Solution {
 public:
  int minOperations(int n) {
    array<int, 1 << 20> dists;
    dists[0] = 0;
    fill(dists.begin() + 1, dists.end(), INT_MAX);
    deque<int> q;
    q.push_back(0);
    while (!q.empty()) {
      const int value = q.front();
      q.pop_front();
      if (value == n) {
        return dists[value];
      }
      for (int bit = 1; bit < dists.size(); bit <<= 1) {
        if (value + bit < dists.size() && dists[value + bit] == INT_MAX) {
          dists[value + bit] = dists[value] + 1;
          q.push_back(value + bit);
        }
        if (value >= bit && dists[value - bit] == INT_MAX) {
          dists[value - bit] = dists[value] + 1;
          q.push_back(value - bit);
        }
      }
    }
    return -1;
  }
};
