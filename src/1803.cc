struct TrieNode {
  array<unique_ptr<TrieNode>, 2> children;
  int count = 0;
};

class Solution {
 public:
  int countPairs(vector<int>& nums, int low, int high) {
    int result = 0;
    TrieNode root;
    vector<tuple<TrieNode*, int, int>> stk;
    for (int num : nums) {
      stk.emplace_back(&root, 15, 0);
      while (!stk.empty()) {
        auto [node, offset, prefix] = stk.back();
        stk.pop_back();
        const int mask = ~((1 << (offset + 1)) - 1);
        if (prefix < (low & mask) || prefix > (high & mask)) {
          continue;
        }
        if ((prefix > (low & mask) && prefix < (high & mask)) || offset < 0) {
          result += node->count;
          continue;
        }
        for (int digit = 0; digit <= 1; ++digit) {
          if (node->children[digit] != nullptr) {
            stk.emplace_back(
                node->children[digit].get(), offset - 1,
                prefix | ((num & (1 << offset)) ^ (digit << offset)));
          }
        }
      }
      TrieNode* node = &root;
      for (int offset = 15; offset >= 0; --offset) {
        const int index = (num & (1 << offset)) == 0 ? 0 : 1;
        if (node->children[index] == nullptr) {
          node->children[index] = make_unique<TrieNode>();
        }
        node = node->children[index].get();
        ++node->count;
      }
    }
    return result;
  }
};
