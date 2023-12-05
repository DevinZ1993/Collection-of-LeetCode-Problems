/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right)
 * {}
 * };
 */
class Solution {
 public:
  Node *expTree(string s) {
    vector<State> stk(1);
    for (char ch : s) {
      if (ch == '+') {
        stk.back().sum = stk.back().eval();
        stk.back().product = nullptr;
        stk.back().minus = false;
      } else if (ch == '-') {
        stk.back().sum = stk.back().eval();
        stk.back().product = nullptr;
        stk.back().minus = true;
      } else if (ch == '*') {
        stk.back().div = false;
      } else if (ch == '/') {
        stk.back().div = true;
      } else if (ch == '(') {
        stk.emplace_back();
      } else if (ch == ')') {
        Node *sub = stk.back().eval();
        stk.pop_back();
        assert(!stk.empty());
        stk.back().add_operand(sub);
      } else {
        stk.back().add_operand(new Node(ch));
      }
    }
    assert(stk.size() == 1);
    return stk.back().eval();
  }

 private:
  struct State {
    Node *eval() const {
      return sum == nullptr ? product
                            : new Node(minus ? '-' : '+', sum, product);
    }

    void add_operand(Node *operand) {
      if (product == nullptr) {
        product = operand;
      } else {
        product = new Node(div ? '/' : '*', product, operand);
      }
    }

    Node *sum = nullptr;
    Node *product = nullptr;
    bool minus = false;
    bool div = false;
  };
};
