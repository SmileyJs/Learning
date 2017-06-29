#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	explicit Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void createNode(Node * &p)
{
	int i;

	cout << "please input an integer: ";
	cin >> i;

	if (0 == i) {
		p = nullptr;
	}
	else {
		p = new Node(i);

		createNode(p->left);
		createNode(p->right);
	}
}

int
getNodeNum(const Node *p)
{
	if (!p)
		return 0;

	return 1 + getNodeNum(p->left) + getNodeNum(p->right);
}

int
getTreeDepth(const Node *p) 
{
	if (!p)
		return 0;

	return 1 + max(getTreeDepth(p->left), getTreeDepth(p->right));
}

void
preOrderTraverse(const Node* p)
{
	if (!p)
		return;

	cout << p->val << " ";
	preOrderTraverse(p->left);
	preOrderTraverse(p->right);
}

void
InOrderTraverse(const Node* p)
{
	if (!p)
		return;
	
	InOrderTraverse(p->left);
	cout << p->val << " ";
	InOrderTraverse(p->right);
}

void
postOrderTraverse(const Node* p)
{	
	if (!p)
		return;
	
	postOrderTraverse(p->left);
	postOrderTraverse(p->right);
	cout << p->val << " ";
}

int
main(int argc, char const *argv[])
{
	Node *p;

	createNode(p);

	cout << "NodeNum: " << getNodeNum(p) << endl;
	cout << "TreeDepth: " << getTreeDepth(p) << endl;

	preOrderTraverse(p);
	cout << endl;
	InOrderTraverse(p);
	cout << endl;
	postOrderTraverse(p);
	cout << endl;

	return 0;
}