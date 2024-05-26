constexpr int mod = 1'000'000'007;

class SegmentTree {
 public:
  explicit SegmentTree(const vector<int> &nums) {
    const int h = static_cast<int>(ceil(log2(nums.size())));
    data_.resize((1 << (h + 1)) - 1);
    for (auto &node : data_) {
      fill(node.begin() + 1, node.end(), INT_MIN);
    }
    for (int i = 0; i < nums.size(); ++i) {
      Update(i, nums[i]);
    }
  }

  void Update(int index, int value) {
    int node_index = index + (data_.size() + 1) / 2 - 1;
    data_[node_index][3] = value;
    while (node_index > 0) {
      const int parent_index = (node_index - 1) / 2;
      const int left_index = (parent_index << 1) + 1;
      const int right_index = (parent_index << 1) + 2;
      for (int state = 0; state < data_[parent_index].size(); ++state) {
        data_[parent_index][state] = INT_MIN;
        for (int mid = 0; mid < 3; ++mid) {
          const int left = data_[left_index][(state & 2) | (mid & 1)];
          const int right = data_[right_index][(state & 1) | (mid & 2)];
          if (left > INT_MIN && right > INT_MIN) {
            data_[parent_index][state] =
                max(data_[parent_index][state], left + right);
          }
        }
      }
      node_index = parent_index;
    }
  }

  int Query() const { return *max_element(data_[0].begin(), data_[0].end()); }

 private:
  vector<array<int, 4>> data_;
};

class Solution {
 public:
  int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries) {
    SegmentTree tree(nums);
    int result = 0;
    for (const vector<int> &query : queries) {
      tree.Update(query[0], query[1]);
      result = (result + tree.Query()) % mod;
    }
    return result;
  }
};
