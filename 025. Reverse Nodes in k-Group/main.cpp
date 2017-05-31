#include"solution.h"
ListNode *create_linkedlist(std::initializer_list<int> list)
{
	auto iter = list.begin();
	ListNode *head = list.size() ? new ListNode(*iter++) : NULL;
	for (ListNode *cur = head; iter != list.end(); cur = cur->next)
		cur->next = new ListNode(*iter++);
	return head;
}
int main()
{
	Solution sol;
	ListNode* list = create_linkedlist({ 1,2 });
	list = sol.reverseKGroup(list,2);
	for (ListNode* p = list; p; p = p->next) {
		cout << p->val << "->";
	}
	cout << "\b\b  " << endl;
	return 0;
}
