class SegmentTree {
 public:
  explicit SegmentTree(int n) {
    const int h = static_cast<int>(ceil(log2(n)));
    data_.resize((1 << (h + 1)) - 1);
    max_index_ = (1 << h) - 1;
  }

  void update(int index, long long value) {
    int node_idx = 0;
    int min_index = 0;
    int max_index = max_index_;
    while (true) {
      data_[node_idx] = max(data_[node_idx], value);
      if (min_index == max_index) {
        break;
      }
      const int mid_index = min_index + (max_index - min_index) / 2;
      if (index <= mid_index) {
        max_index = mid_index;
        node_idx = 2 * node_idx + 1;
      } else {
        min_index = mid_index + 1;
        node_idx = 2 * node_idx + 2;
      }
    }
  }

  long long get(int p, int r) const {
    long long result = 0;
    vector<tuple<int, int, int>> stk;
    stk.emplace_back(0, 0, max_index_);
    while (!stk.empty()) {
      auto [node_idx, min_index, max_index] = stk.back();
      stk.pop_back();
      if (min_index >= p && max_index <= r) {
        result = max(result, data_[node_idx]);
        continue;
      }
      const int mid_index = min_index + (max_index - min_index) / 2;
      if (p <= mid_index) {
        stk.emplace_back(node_idx * 2 + 1, min_index, mid_index);
      }
      if (r > mid_index) {
        stk.emplace_back(node_idx * 2 + 2, mid_index + 1, max_index);
      }
    }
    return result;
  }

 private:
  vector<long long> data_;
  int max_index_;
};

class Solution {
 public:
  long long maxBalancedSubsequenceSum(vector<int>& nums) {
    map<int, int> indices;
    for (int i = 0; i < nums.size(); ++i) {
      indices.emplace(nums[i] - i, 0);
    }
    int n_values = 0;
    for (auto it = indices.begin(); it != indices.end(); ++it) {
      it->second = n_values++;
    }
    SegmentTree tree(n_values);
    vector<long long> dp(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      const int index = indices.at(nums[i] - i);
      dp[i] = nums[i] + tree.get(0, index);
      tree.update(index, dp[i]);
    }
    return *max_element(dp.begin(), dp.end());
  }
};
