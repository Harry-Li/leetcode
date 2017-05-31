## [024. Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/#/description)
### 题目要求：
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
### 我的思路：
用三个指针，样例中，p1指向2，p2指向1，p3指向3
```c
	ListNode* swapPairs(ListNode* head) {
		if (!head) return NULL;
		if (!head->next) return head;
		ListNode *newhead = head->next;
		ListNode *p1 = head->next, *p2 = head, *p3 = NULL;
		while (true) {
			p2->next = p1->next;
			p1->next = p2;
			p3 = p2->next;
			if (!p3 || !p3->next) break;
			p1 = p3->next;
			p2->next = p1;
			p2 = p3;
		}
		return newhead;
	}

```
### 方法二：
方法比较简单，但是递归的空间复杂度为O(n)，不满足题目条件
```c
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        
        return next;
    }
```
### 方法三：
不是很好理解，解释[by zachluna](https://discuss.leetcode.com/topic/18860/7-8-lines-c-python-ruby/12)
```c
	ListNode* swapPairs(ListNode* head) {
		ListNode **pp = &head, *a, *b;
		while ((a = *pp) && (b = a->next)) {
			a->next = b->next;
			b->next = a;
			*pp = b;
			pp = &(a->next);
		}
		return head;
	}
```
