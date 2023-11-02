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
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode dummy(0, head);
    for (ListNode *tail = &dummy; tail != nullptr;) {
      ListNode *next_tail = tail->next;
      ListNode *end = tail->next;
      int count = 0;
      while (count < k && end != nullptr) {
        ++count;
        end = end->next;
      }
      if (count < k) {
        break;
      }
      ListNode *top = end;
      for (ListNode *node = tail->next; node != end;) {
        ListNode *next_node = node->next;
        node->next = top;
        top = node;
        node = next_node;
      }
      tail->next = top;
      tail = next_tail;
    }
    return dummy.next;
  }
};
