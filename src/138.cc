/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
 public:
  Node *copyRandomList(Node *head) {
    unordered_map<Node *, Node *> indices;
    unique_ptr<Node> dummy = make_unique<Node>(0);
    Node *tail = dummy.get();
    for (Node *node = head; node != nullptr; node = node->next) {
      tail = tail->next = new Node(node->val);
      indices.emplace(node, tail);
    }
    tail->next = nullptr;
    for (Node *node = head, *new_node = dummy->next; node != nullptr;
         node = node->next, new_node = new_node->next) {
      assert(new_node != nullptr);
      if (node->random != nullptr) {
        new_node->random = indices[node->random];
      }
    }
    return dummy->next;
  }
};
