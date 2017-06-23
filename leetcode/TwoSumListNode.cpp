#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	explicit ListNode(int x) : val(x), next(nullptr) {} 
};

void print(ListNode* l)
{
	ListNode* p = l;
	for (; p; p = p->next) {
		cout << p->val << endl;
	}
}

class Solution
{
public:
	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (nullptr == l1)
			l1 = new ListNode(0);
		if (nullptr == l2)
			l2 = new ListNode(0);
		cout << l1 ->val << " " << l2->val << endl;
		l1->val += l2->val;
		cout << l1->val << endl;

		if (0 == l1->val) {
			return l1;
		}
		else if (l1->val > 9) {
			if (l1->next) {
				l1->next->val += l1->val / 10;
			}
			else {
				l1->next = new ListNode(l1->val / 10);
			}

			l1->val %= 10;
		}

		addTwoNumbers(l1->next, l2->next);

		return l1;
	}
};

int
main(int argc, char const *argv[])
{
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	print(l1);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	print(l2);

	ListNode* l3 = new ListNode(0);
	ListNode* l4 = new ListNode(7);
	l4->next = new ListNode(3);

	cout << "result:\n";

	print(Solution::addTwoNumbers(l3, l4));

	return 0;
}