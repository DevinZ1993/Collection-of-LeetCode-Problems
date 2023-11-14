class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    const int n = arr.size();
    vector<int> indices(n, n - 1);
    const auto cmp = [&indices, &arr](int i, int j) {
      return 1LL * arr[i] * arr[indices[j]] > 1LL * arr[j] * arr[indices[i]];
    };
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    for (int i = 0; i < n; ++i) {
      q.push(i);
    }
    for (; k > 1; --k) {
      const int index = q.top();
      q.pop();
      if (--indices[index] >= 0) {
        q.push(index);
      }
    }
    return vector{arr[q.top()], arr[indices[q.top()]]};
  }
};
