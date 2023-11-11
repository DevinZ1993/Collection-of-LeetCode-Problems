class Solution {
 public:
  bool isValidSerialization(string preorder) {
    vector<int> stk{2};
    for (int i = 0, j = 1; j <= preorder.size(); ++j) {
      if (j == preorder.size() || preorder[j] == ',') {
        if (j == i + 1 && preorder[i] == '#') {
          --stk.back();
          while (stk.back() == 0) {
            stk.pop_back();
            if (stk.empty()) {
              return false;
            }
            --stk.back();
          }
        } else {
          stk.push_back(2);
        }
        i = j + 1;
      }
    }
    return stk.size() == 1 && stk[0] == 1;
  }
};
