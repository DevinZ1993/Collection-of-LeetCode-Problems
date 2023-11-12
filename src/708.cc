/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
 public:
  Node *insert(Node *head, int insertVal) {
    unique_ptr<Node> new_node = make_unique<Node>(insertVal);
    if (head == nullptr) {
      new_node->next = new_node.get();
      return new_node.release();
    }
    Node *ret_val = head;
    if (head->val <= head->next->val) {
      const Node *end = head;
      head = head->next;
      for (; head != end; head = head->next) {
        if (head->val > head->next->val) {
          break;
        }
      }
    }
    if (head->val > head->next->val) {
      if (head->next->val < insertVal) {
        const Node *end = head;
        head = head->next;
        for (; head != end; head = head->next) {
          if (head->next->val >= insertVal) {
            break;
          }
        }
      }
    }
    new_node->next = head->next;
    head->next = new_node.release();
    return ret_val;
  }
};
