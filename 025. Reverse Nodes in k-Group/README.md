## [025. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/#/description)
### 题目要求：
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

这题是[024. Swap Nodes in Pairs](https://github.com/Harry-Li/leetcode/tree/master/024.%20Swap%20Nodes%20in%20Pairs)的扩展
### 我的思路：
用栈，先进后出，可以简化指针运算，大小为k* sizeof(ListNode*)，也算是常量大小吧。
```c
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head) return NULL;
		stack<ListNode*>stack1;
		int m = k, num = 0;
		ListNode* p = head, dummy(0), *pcur = &dummy;
		while (p) {
			++num;
			p = p->next;
		}
		p = head;
		while (num >= k) {
			m = k;
			while (m--) {
				stack1.push(p);
				p = p->next;
			}
			m = k;
			while (m--) {
				pcur->next = stack1.top();
				stack1.pop();
				pcur = pcur->next;
				pcur->next = NULL;
			}
			num -= k;
		}
		if (p) pcur->next = p;
		return dummy.next;
	}
```
### 方法二：
https://discuss.leetcode.com/topic/9839/20-line-iterative-c-solution
```c
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == NULL || k == 1) return head;
		int num = 0;
		ListNode *preheader = new ListNode(-1);
		preheader->next = head;
		ListNode *cur = preheader, *nex, *pre = preheader;
		while (cur = cur->next)
			num++;
		while (num >= k) {
			cur = pre->next;
			nex = cur->next;
			for (int i = 1; i<k; ++i) {
				cur->next = nex->next;
				nex->next = pre->next;
				pre->next = nex;
				nex = cur->next;
			}
			pre = cur;
			num -= k;
		}
		return preheader->next;
	}
```
