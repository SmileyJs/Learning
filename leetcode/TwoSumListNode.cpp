#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	explicit ListNode(int x) : val(x), next(nullptr) {} 
};

void print(ListNode *l)
{
	ListNode *p = l;
	while (p) {
		cout << p->val << endl;
		p = p->next;
	}
}

ListNode *
addTwoNumbers(ListNode *lhs, ListNode *rhs) {
	ListNode *pre = new ListNode(0), *head = pre;
	int extra = 0;

	while (lhs && rhs) {
		int sum = lhs->val + rhs->val + extra;
		extra = sum / 10;

		pre->next = new ListNode(sum % 10);
		pre = pre->next;
		lhs = lhs->next;
		rhs = rhs->next;
	}
	while (lhs) {
		int sum = lhs->val + extra;
		extra = sum / 10;

		pre->next = new ListNode(sum % 10);
		pre = pre->next;
		lhs = lhs->next;
	}
	while (rhs) {
		int sum = rhs->val + extra;
		extra = sum / 10;

		pre->next = new ListNode(sum % 10);
		pre = pre->next;
		rhs = rhs->next;
	}
	if (extra) {
		pre->next = new ListNode(extra);
	}

	return head->next;
}

ListNode *
addTwoNumbers2(ListNode *lhs, ListNode *rhs) {
	ListNode *pre = new ListNode(0), *head = pre;
	int extra = 0;

	while (lhs || rhs) {
		int sum = (lhs ? lhs->val : 0) + (rhs ? rhs->val : 0) + extra;
		extra = sum / 10;

		pre->next = new ListNode(sum % 10);
		pre = pre->next;

		if (lhs)
			lhs = lhs->next;
		if (rhs)
			rhs = rhs->next;
	}

	if (extra) {
		pre->next = new ListNode(extra);
	}

	return head->next;
}

int
main(int argc, char const *argv[])
{
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	print(l1);

	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	print(l2);

	ListNode *l3 = new ListNode(0);
	ListNode *l4 = new ListNode(7);
	l4->next = new ListNode(3);

	cout << "result:\n";

	print(addTwoNumbers2(l3, l4));

	return 0;
}