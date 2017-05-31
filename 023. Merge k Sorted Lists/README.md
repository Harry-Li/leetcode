## [023. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/#/description)
### 题目要求：
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
### 我的思路：
每次遍历所有链表，找最小的一个节点，插入，然后移到该链表的下一个节点，直到所有链表都为空。<br>
设链表平均长度为n，则时间复杂度为O(nk^2)。
```c
	int minindex(vector<ListNode*>& plists) {
		int min = INT_MAX, index;
		for (int i = 0; i<plists.size(); i++) {
			if (plists[i] && plists[i]->val<min) {
				min = plists[i]->val;
				index = i;
			}
		}
		return index;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int size = lists.size(), count = size;
		if (lists.empty()) return NULL;
		vector<ListNode*> plists(lists);
		ListNode* head = new ListNode(-1), *p = head;
		for (int i = 0; i < plists.size(); i++) {
			if (plists[i] == NULL) count--;
		}
		int index = 0;
		while (count) {
			index = minindex(plists);
			p->next = plists[index];
			p = p->next;
			plists[index] = (plists[index])->next;
			if (plists[index] == NULL) --count;
		}
		return head->next;
	}
```
### 推荐思路与解法：
借鉴了[021. Merge Two Sorted Lists](https://github.com/Harry-Li/leetcode/tree/master/021.%20Merge%20Two%20Sorted%20Lists)中的函数<br>
时间复杂度为O(nk*logk)
```c
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }     
        return lists.front();
    }
    //下面是递归，也可以用循环
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
