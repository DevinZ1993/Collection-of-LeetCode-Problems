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
  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode dummy{0, head};
    ListNode *mid = &dummy;
    for (ListNode *node = &dummy;
         node->next != nullptr && node->next->next != nullptr;
         node = node->next->next) {
      mid = mid->next;
    }
    ListNode *other = sortList(mid->next);
    mid->next = nullptr;
    head = sortList(head);
    ListNode *tail = &dummy;
    while (head != nullptr && other != nullptr) {
      if (head->val < other->val) {
        tail = tail->next = head;
        head = head->next;
      } else {
        tail = tail->next = other;
        other = other->next;
      }
    }
    if (head != nullptr) {
      tail->next = head;
    } else {
      tail->next = other;
    }
    return dummy.next;
  }
};
