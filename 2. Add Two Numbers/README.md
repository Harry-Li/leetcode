## 2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/#/description
### 题目要求：
给定两个表示非负整数的链表，倒序存放整数的每一位，求和，并用同样的方法表示。<br>
例如：<br>
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)<br>
Output: 7 -> 0 -> 8<br>
表示342+465=807
### 我的思路：
两个链表都不为空时进行循环进位求值，某个为空后进行判断。
### 推荐思路与解法：
实际上循环条件可以改为判断两个链表不都为空，如果某个链表为空，仍可以循环，只是把对应为置为0，简化代码。
```c
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p = new ListNode(0), *sum = p;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		int a, b, c = 0;
		while (p1 != NULL || p2 != NULL) {
			a = p1 ? p1->val : 0;
			b = p2 ? p2->val : 0;
			ListNode *pNode = new ListNode((a + b + c) % 10);
			p->next = pNode;
			p = p->next;
			p1 = p1 ? p1->next : p1;
			p2 = p2 ? p2->next : p2;
			c = (c + a + b) / 10;
		}
		if (c != 0) p->next = new ListNode(1);
		return sum->next;
	}
```
