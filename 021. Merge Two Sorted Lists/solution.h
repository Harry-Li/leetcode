#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
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
};
