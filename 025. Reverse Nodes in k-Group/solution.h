#include<iostream>
#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head) return NULL;
		stack<ListNode*>stack1;
		int m = k, num = 0;
		ListNode* p = head, dummy(0), *pcur = &dummy;
		while (p){
		    ++num;
		    p=p->next;
		}
		p=head;
		while (num>=k) {
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
			num-=k;
		}
		if (p) pcur->next = p;
		return dummy.next;
	}
};
