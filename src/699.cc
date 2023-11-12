class SegmentTree {
 public:
  explicit SegmentTree(int n) {
    const int h = static_cast<int>(ceil(log2(n)));
    data_.resize((1 << (h + 1)) - 1);
    max_index_ = (1 << h) - 1;
  }

  int getMax(int p, int r) const {
    vector<tuple<int, int, int>> stk;
    stk.emplace_back(0, 0, max_index_);
    int result = INT_MIN;
    while (!stk.empty()) {
      auto [node_index, min_index, max_index] = stk.back();
      stk.pop_back();
      if (min_index >= p && max_index <= r) {
        result = max(result, data_[node_index]);
        continue;
      }
      const int mid_index = min_index + (max_index - min_index) / 2;
      if (mid_index >= p) {
        stk.emplace_back(2 * node_index + 1, min_index, mid_index);
      }
      if (r >= mid_index + 1) {
        stk.emplace_back(2 * node_index + 2, mid_index + 1, max_index);
      }
    }
    return result;
  }

  void update(int p, int r, int val) {
    vector<tuple<int, int, int>> stk;
    stk.emplace_back(0, 0, max_index_);
    while (!stk.empty()) {
      auto [node_index, min_index, max_index] = stk.back();
      stk.pop_back();
      data_[node_index] = max(data_[node_index], val);
      if (max_index == min_index) {
        continue;
      }
      const int mid_index = min_index + (max_index - min_index) / 2;
      if (mid_index >= p) {
        stk.emplace_back(2 * node_index + 1, min_index, mid_index);
      }
      if (r >= mid_index + 1) {
        stk.emplace_back(2 * node_index + 2, mid_index + 1, max_index);
      }
    }
  }

 private:
  vector<int> data_;
  int max_index_;
};

class Solution {
 public:
  vector<int> fallingSquares(vector<vector<int>> &positions) {
    map<int, int> indices;
    for (const auto &position : positions) {
      indices.emplace(position[0], 0);
      indices.emplace(position[0] + position[1], 0);
    }
    int n_values = 0;
    for (auto it = indices.begin(); it != indices.end(); ++it) {
      it->second = n_values++;
    }
    vector<int> results;
    results.reserve(positions.size());
    SegmentTree tree(n_values);
    int max_height = 0;
    for (const auto &position : positions) {
      const int min_index = indices.at(position[0]);
      const int max_index = indices.at(position[0] + position[1]) - 1;
      const int height = tree.getMax(min_index, max_index) + position[1];
      tree.update(min_index, max_index, height);
      max_height = max(max_height, height);
      results.push_back(max_height);
    }
    return results;
  }
};
