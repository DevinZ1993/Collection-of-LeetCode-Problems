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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = nullptr;
    vector<TreeNode*> stk;
    for (int num : preorder) {
      if (root == nullptr) {
        root = new TreeNode(num);
        stk.push_back(root);
        continue;
      }
      if (stk.back()->val > num) {
        stk.back()->left = new TreeNode(num);
        stk.push_back(stk.back()->left);
        continue;
      }
      TreeNode* parent = nullptr;
      while (!stk.empty() && stk.back()->val < num) {
        parent = stk.back();
        stk.pop_back();
      }
      stk.push_back(new TreeNode(num));
      parent->right = stk.back();
    }
    return root;
  }
};
