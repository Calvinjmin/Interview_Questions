// Tracking Two Linked Lists - [Leetcode 2](https://leetcode.com/problems/add-two-numbers/description/)

#include "./listNode.h"

using namespace std;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *ans = new ListNode(0);
  ListNode *curr = ans;
  int carry = 0;

  while (l1 || l2 || carry != 0) {
    int x = l1 ? l1->val : 0;
    int y = l2 ? l2->val : 0;
    int sum = carry + x + y;
    carry = sum / 10;
    curr->next = new ListNode(sum % 10);
    curr = curr->next;
    l1 = l1 ? l1->next : nullptr;
    l2 = l2 ? l2->next : nullptr;
  }
  ListNode *res = ans->next;
  delete ans;
  return res;
}