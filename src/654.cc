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
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    if (nums.empty()) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
      TreeNode *node = new TreeNode(nums[i]);
      if (nums[i] > root->val) {
        node->left = root;
        root = node;
        continue;
      }
      TreeNode *parent = root;
      while (parent->right != nullptr && parent->right->val > nums[i]) {
        parent = parent->right;
      }
      node->left = parent->right;
      parent->right = node;
    }
    return root;
  }
};
