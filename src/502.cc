class Solution {
 public:
  int findMaximizedCapital(int k, int w, vector<int>& profits,
                           vector<int>& capital) {
    const int n = profits.size();
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(),
         [&capital](int i, int j) { return capital[i] < capital[j]; });
    priority_queue<int> q;
    for (int i = 0, j = 0; i < k; ++i) {
      while (j < indices.size() && capital[indices[j]] <= w) {
        q.push(profits[indices[j]]);
        ++j;
      }
      if (q.empty()) {
        break;
      }
      w += q.top();
      q.pop();
    }
    return w;
  }
};
