/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string result;
    vector<TreeNode*> stk = {root};
    while (!stk.empty()) {
      TreeNode* node = stk.back();
      stk.pop_back();
      if (!result.empty()) {
        result.push_back(',');
      }
      if (node == nullptr) {
        result.push_back('#');
        continue;
      }
      result.append(to_string(node->val));
      stk.push_back(node->right);
      stk.push_back(node->left);
    }
    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<pair<unique_ptr<TreeNode>, int>> stk;
    stk.emplace_back(make_unique<TreeNode>(), 0);
    for (int i = 0, j = 0; j <= data.size(); ++j) {
      if (j == data.size() || data[j] == ',') {
        if (j == i + 1 && data[i] == '#') {
          stk.emplace_back(nullptr, 2);
          while (stk.back().second == 2) {
            auto child = move(stk.back().first);
            stk.pop_back();
            assert(!stk.empty());
            if (stk.back().second++ == 0) {
              stk.back().first->left = child.release();
            } else {
              stk.back().first->right = child.release();
            }
          }
        } else {
          stk.emplace_back(make_unique<TreeNode>(stoi(data.substr(i, j - i))),
                           0);
        }
        i = j + 1;
      }
    }
    assert(stk.size() == 1);
    return stk[0].first->left;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
