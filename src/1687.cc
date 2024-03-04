class Solution {
 public:
  int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes,
                    int maxWeight) {
    const int n = boxes.size();
    vector<int> cnts(n + 1);
    for (int i = 0; i < n; ++i) {
      cnts[i + 1] =
          cnts[i] + (i == 0 || boxes[i][0] != boxes[i - 1][0] ? 1 : 0);
    }
    vector<int> dp(n + 1);
    deque<int> q;
    q.push_back(0);
    int weight_sum = 0;
    for (int i = 0, j = 1; j <= n; ++j) {
      weight_sum += boxes[j - 1][1];
      while (j > i + maxBoxes || weight_sum > maxWeight) {
        weight_sum -= boxes[i][1];
        if (q.front() == i) {
          q.pop_front();
        }
        ++i;
      }
      assert(!q.empty());
      dp[j] = dp[q.front()] + cnts[j] - cnts[q.front() + 1] + 2;
      if (j == n) {
        break;
      }
      while (!q.empty() &&
             dp[q.back()] - cnts[q.back() + 1] > dp[j] - cnts[j + 1]) {
        q.pop_back();
      }
      q.push_back(j);
    }
    return dp[n];
  }
};
