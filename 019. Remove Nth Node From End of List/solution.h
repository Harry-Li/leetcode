#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
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
};
