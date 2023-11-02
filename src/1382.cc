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
  TreeNode *balanceBST(TreeNode *root) {
    root = flatten(root, nullptr);
    int count = 0;
    for (TreeNode *node = root; node != nullptr; node = node->right) {
      ++count;
    }
    return buildTree(root, count);
  }

 private:
  TreeNode *flatten(TreeNode *root, TreeNode *right_most) {
    if (root == nullptr) {
      return right_most;
    }
    root->right = flatten(root->right, right_most);
    return flatten(root->left, root);
  }
  TreeNode *buildTree(TreeNode *&node, int count) {
    if (count == 0) {
      return nullptr;
    }
    TreeNode *left = buildTree(node, count / 2);
    TreeNode *root = node;
    root->left = left;
    node = node->right;
    root->right = buildTree(node, (count - 1) / 2);
    return root;
  }
};
