#include <iostream>
#include <set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	explicit ListNode(int x) : val(x), next(nullptr) {}
};

bool
hasCircle(ListNode *head)
{
	// set<ListNode*> listSet;

	// while (head) {
	// 	if (listSet.count(head))
	// 		return true;
	// 	listSet.insert(head);
	// 	head = head->next;
	// }

	ListNode *slow = head, *fast = head;

	while (fast && fast->next) {
		if (fast->next == slow || fast->next->next == slow)
			return true;

		slow = slow->next;
		fast = fast->next->next;
	}

	return false;
}

int
main(int argc, char const *argv[])
{
	ListNode head(0);

	ListNode *p = &head;
	for (int i = 1; i < 10; ++i) {
		p->next = new ListNode(i);
		p = p->next;
	}

	p = &head;

	p->next->next->next->next->next = p;

	cout << hasCircle(&head) << endl;

	return 0;
}