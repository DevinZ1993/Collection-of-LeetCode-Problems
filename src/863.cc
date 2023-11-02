/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    vector<TreeNode *> path;
    vector<pair<TreeNode *, int>> stk;
    stk.emplace_back(root, 0);
    while (!stk.empty()) {
      auto [node, state] = stk.back();
      stk.pop_back();
      if (state == 1) {
        path.pop_back();
        continue;
      }
      path.push_back(node);
      stk.emplace_back(node, 1);
      if (node == target) {
        break;
      }
      if (node->left != nullptr) {
        stk.emplace_back(node->left, 0);
      }
      if (node->right != nullptr) {
        stk.emplace_back(node->right, 0);
      }
    }
    vector<int> results;
    findNodesAtDepth(target, k, results);
    --k;
    for (; k > 0 && path.size() >= 2; --k) {
      TreeNode *node = path.back();
      path.pop_back();
      if (path.back()->left == node) {
        findNodesAtDepth(path.back()->right, k - 1, results);
      } else {
        findNodesAtDepth(path.back()->left, k - 1, results);
      }
    }
    if (k == 0 && path.size() >= 2) {
      path.pop_back();
      results.push_back(path.back()->val);
    }
    return results;
  }

 private:
  void findNodesAtDepth(TreeNode *root, int target_depth, vector<int> &values) {
    if (root == nullptr) {
      return;
    }
    vector<pair<TreeNode *, int>> stk;
    stk.emplace_back(root, target_depth);
    while (!stk.empty()) {
      auto [node, depth] = stk.back();
      stk.pop_back();
      if (depth == 0) {
        values.push_back(node->val);
        continue;
      }
      if (node->left != nullptr) {
        stk.emplace_back(node->left, depth - 1);
      }
      if (node->right != nullptr) {
        stk.emplace_back(node->right, depth - 1);
      }
    }
  }
};
