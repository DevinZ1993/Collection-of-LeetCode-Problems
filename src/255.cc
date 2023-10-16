class Solution {
 public:
  bool verifyPreorder(vector<int>& preorder) {
    vector<int> stk;
    int min_val = INT_MIN;
    for (int num : preorder) {
      if (num < min_val) {
        return false;
      }
      while (!stk.empty() && stk.back() < num) {
        min_val = max(min_val, stk.back() + 1);
        stk.pop_back();
      }
      stk.push_back(num);
    }
    return true;
  }
};
