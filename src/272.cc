/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<int> closestKValues(TreeNode *root, double target, int k) {
    vector<TreeNode *> right_stk;
    for (TreeNode *node = root; node != nullptr;) {
      right_stk.push_back(node);
      if (node->val == target) {
        break;
      } else if (node->val < target) {
        node = node->right;
      } else {
        node = node->left;
      }
    }
    constexpr auto get_left = [](TreeNode *node) { return node->left; };
    constexpr auto get_right = [](TreeNode *node) { return node->right; };
    vector<int> results;
    results.reserve(k);
    vector<TreeNode *> left_stk(right_stk);
    if (left_stk.back()->val > target) {
      fetchNext(left_stk, get_right, get_left);
    } else {
      fetchNext(right_stk, get_left, get_right);
    }
    while (results.size() < k && !left_stk.empty() && !right_stk.empty()) {
      if (target * 2 - left_stk.back()->val - right_stk.back()->val < 0) {
        results.push_back(left_stk.back()->val);
        fetchNext(left_stk, get_right, get_left);
      } else {
        results.push_back(right_stk.back()->val);
        fetchNext(right_stk, get_left, get_right);
      }
    }
    while (results.size() < k && !left_stk.empty()) {
      results.push_back(left_stk.back()->val);
      fetchNext(left_stk, get_right, get_left);
    }
    while (results.size() < k && !right_stk.empty()) {
      results.push_back(right_stk.back()->val);
      fetchNext(right_stk, get_left, get_right);
    }
    return results;
  }

 private:
  void fetchNext(vector<TreeNode *> &stk,
                 std::function<TreeNode *(TreeNode *)> get_left,
                 std::function<TreeNode *(TreeNode *)> get_right) {
    if (get_right(stk.back()) != nullptr) {
      stk.push_back(get_right(stk.back()));
      while (get_left(stk.back()) != nullptr) {
        stk.push_back(get_left(stk.back()));
      }
    } else {
      while (!stk.empty()) {
        auto *node = stk.back();
        stk.pop_back();
        if (stk.empty() || get_left(stk.back()) == node) {
          break;
        }
      }
    }
  }
};
