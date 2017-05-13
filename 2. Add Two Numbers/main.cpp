#include"solution.h"
int main()
{
	ListNode* L11 = new ListNode(2);
	ListNode* L12 = new ListNode(4);
	ListNode* L13 = new ListNode(3);
	ListNode* L21 = new ListNode(5);
	ListNode* L22 = new ListNode(6);
	ListNode* L23 = new ListNode(4);
	L11->next = L12;
	L12->next = L13;
	L21->next = L22;
	L22->next = L23;
	Solution sol;
	ListNode* p = sol.addTwoNumbers(L11, L21);
	for (ListNode* pcur = p; pcur; pcur = pcur->next) {
		cout << pcur->val << "->";
	}
	cout << "\b\b  " << endl;
	return 0;
}

