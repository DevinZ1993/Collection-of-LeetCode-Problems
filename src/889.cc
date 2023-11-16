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
  TreeNode* constructFromPrePost(vector<int>& preorder,
                                 vector<int>& postorder) {
    unique_ptr<TreeNode> dummy = make_unique<TreeNode>();
    vector<TreeNode*> stk{dummy.get()};
    for (int i = 0, j = 0; i < preorder.size(); ++i) {
      stk.push_back(new TreeNode(preorder[i]));
      while (j < postorder.size() && postorder[j] == stk.back()->val) {
        TreeNode* child = stk.back();
        stk.pop_back();
        assert(!stk.empty());
        if (stk.back()->left == nullptr) {
          stk.back()->left = child;
        } else {
          stk.back()->right = child;
        }
        ++j;
      }
    }
    assert(stk.size() == 1);
    return stk.back()->left;
  }
};
