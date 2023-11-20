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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    ListNode* tail = &dummy;
    int cin = 0;
    for (; l1 != nullptr && l2 != nullptr; l1 = l1->next, l2 = l2->next) {
      const int val = l1->val + l2->val + cin;
      tail = tail->next = new ListNode(val % 10);
      cin = val / 10;
    }
    if (l2 != nullptr) {
      swap(l1, l2);
    }
    for (; l1 != nullptr; l1 = l1->next) {
      const int val = l1->val + cin;
      tail = tail->next = new ListNode(val % 10);
      cin = val / 10;
    }
    if (cin > 0) {
      tail = tail->next = new ListNode(cin);
    }
    tail->next = nullptr;
    return dummy.next;
  }
};
