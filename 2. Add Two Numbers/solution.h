#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution {
public:
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
};
/*
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p = new ListNode(0);
		ListNode* sum = p;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		int a, b, c = 0;
		while (p1 != NULL&&p2 != NULL) {
			a = p1->val;
			b = p2->val;
			ListNode *pNode = new ListNode((a + b + c) % 10);
			p->next = pNode;
			p = p->next;
			p1 = p1->next;
			p2 = p2->next;
			c = (c + a + b) / 10;
		}
		if (p1 == NULL&&p2 == NULL) {
			if (c == 1) p->next = new ListNode(1);
			return sum->next;
		}
		if (p1 == NULL) {
			while (p2 != NULL) {
				b = p2->val;
				ListNode *pNode = new ListNode((b + c) % 10);
				p->next = pNode;
				p = p->next;
				p2 = p2->next;
				c = (c + b) / 10;
			}
			if (c == 0) return sum->next;
			else {
				p->next = new ListNode(1);
				return sum->next;
			}
		}
		else {
			while (p1 != NULL) {
				a = p1->val;
				ListNode *pNode = new ListNode((a + c) % 10);
				p->next = pNode;
				p = p->next;
				p1 = p1->next;
				c = (c + a) / 10;
			}
			if (c == 0) return sum->next;
			else {
				p->next = new ListNode(1);
				return sum->next;
			}
		}
	}
};
*/

