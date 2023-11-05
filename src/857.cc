class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    const int n = quality.size();
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&quality, &wage](int i, int j) {
      return 1LL * wage[i] * quality[j] < 1LL * wage[j] * quality[i];
    });

    double result = DBL_MAX;
    priority_queue<int> max_heap;
    double ratio = 0.0;
    long long quality_sum = 0;
    for (int index : indices) {
      ratio = 1.0 * wage[index] / quality[index];
      max_heap.push(quality[index]);
      quality_sum += quality[index];
      if (max_heap.size() > k) {
        quality_sum -= max_heap.top();
        max_heap.pop();
      }
      if (max_heap.size() == k) {
        result = min(result, ratio * quality_sum);
      }
    }
    return result;
  }
};
