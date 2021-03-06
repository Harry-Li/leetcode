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
	ListNode* list1 = create_linkedlist({ 1,3,5 });
	ListNode* list2 = create_linkedlist({ 2,4,6 });
	ListNode* list = sol.mergeTwoLists(list1, list2);
	for (ListNode* p = list; p; p = p->next) {
		cout << p->val << "->";
	}
	cout << "\b\b  " << endl;
	return 0;
}
