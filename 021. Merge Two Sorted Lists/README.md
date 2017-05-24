## [021. Merge Two Sorted Lists](https://leetcode.com/problems/valid-parentheses/#/description)
### 题目要求：
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
### 解法一：
循环
```c
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = NULL, *p = NULL;
		ListNode* p1 = l1, *p2 = l2;
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		if (p1->val>p2->val) {
			head = p2;
			p2 = p2->next;
		}
		else {
			head = p1;
			p1 = p1->next;
		}
		p = head;
		while (p1&&p2) {
			if (p1->val>p2->val) {
				p->next = p2;
				p2 = p2->next;
				p = p->next;
			}
			else {
				p->next = p1;
				p1 = p1->next;
				p = p->next;
			}
		}
		if (p1) p->next = p1;
		else p->next = p2;
		return head;
	}
```
### 解法二：
递归
```c
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
```
