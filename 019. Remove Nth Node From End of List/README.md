## [019. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/#/description)
### 题目要求：
Given a linked list, remove the nth node from the end of list and return its head.
### 解法：
```c
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head) return NULL;
		ListNode* p1 = head, *p2 = head;
		while (n--) p1 = p1->next;
		if (!p1) return head->next;
		while (p1->next) {
			p1 = p1->next;
			p2 = p2->next;
		}
		p2->next = p2->next->next;
		return head;
	}
```
