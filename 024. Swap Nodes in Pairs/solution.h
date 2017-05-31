#include<iostream>
using namespace std;
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
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
};
