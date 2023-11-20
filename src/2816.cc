/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode *doubleIt(ListNode *head) {
    head = reverse(head);
    ListNode dummy;
    ListNode *tail = &dummy;
    int cin = 0;
    for (ListNode *node = head; node != nullptr; node = node->next) {
      const int val = 2 * node->val + cin;
      tail = tail->next = new ListNode(val % 10);
      cin = val / 10;
    }
    if (cin > 0) {
      tail->next = new ListNode(cin);
    }
    return reverse(dummy.next);
  }

 private:
  ListNode *reverse(ListNode *head) {
    ListNode *tail = nullptr;
    for (ListNode *node = head; node != nullptr;) {
      ListNode *next = node->next;
      node->next = tail;
      tail = node;
      node = next;
    }
    return tail;
  }
};
