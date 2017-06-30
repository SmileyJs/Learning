#include <iostream>
#include <queue>

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
preOrderTraverse(const Node *p)
{
	if (!p)
		return;

	cout << p->val << " ";
	preOrderTraverse(p->left);
	preOrderTraverse(p->right);
}

void
InOrderTraverse(const Node *p)
{
	if (!p)
		return;
	
	InOrderTraverse(p->left);
	cout << p->val << " ";
	InOrderTraverse(p->right);
}

void
postOrderTraverse(const Node *p)
{	
	if (!p)
		return;
	
	postOrderTraverse(p->left);
	postOrderTraverse(p->right);
	cout << p->val << " ";
}

void
levelTraverse(Node* const p)
{
	if (!p)
		return;

	queue<Node *> q;
	q.push(p);

	while (!q.empty()) {
		Node *pNode = q.front();
		q.pop();
		cout << pNode->val;

		if (pNode->left) 
			q.push(pNode->left);
		if (pNode->right)
			q.push(pNode->right);
	}
}

void
convertDoubleLinkedNode(Node *root, Node *&first, Node *&last)
{
	Node *pLeftFirst, *pLeftLast, *pRightFirst, *pRightLast;

	if (!root) {
		first = nullptr;
		last = nullptr;
		return;
	}

	if (!root->left) {
		first = root;
	}
	else {
		convertDoubleLinkedNode(root->left, pLeftFirst, pLeftLast);

		first = pLeftFirst;
		root->left = pLeftLast;
		pLeftLast->right = root;
	}

	if (!root->right) {
		last = root;
	}
	else {
		convertDoubleLinkedNode(root->right, pRightFirst, pRightLast);

		last = pRightLast;
		root->right = pRightFirst;
		pRightFirst->left = root;
	}
}

int
getLevelNodeNum(Node *p, int k)
{
	if (!p || k < 1) {
		return 0;
	}

	if (1 == k) {
		return 1;
	}

	return getLevelNodeNum(p->left, k-1) + getLevelNodeNum(p->right, k-1);
}

int
getLeafNum(Node *p)
{
	if (!p)
		return 0;

	if (!p->left && !p->right)
		return 1;

	return 1 + getLeafNum(p->left) + getLeafNum(p->right);
}

bool
structureCmp(Node *a, Node *b)
{
	if (!a && !b)
		return true;

	if (!a || !b) 
		return false;

	return structureCmp(a->left, b->left) && structureCmp(a->right, b->right);
}

bool
isAVLTree(Node *p)
{
	if (!p)
		return true;
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

	cout << "levelTraverse: ";
	levelTraverse(p);
	cout << endl;

	cout << "please input the level num: ";
	int k = 0;
	cin >> k;
	cout << getLevelNodeNum(p, k) << endl;

	cout << "leafNum: ";
	cout << getLeafNum(p) << endl;

	// Node *q;
	// cout << "please input the second tree: ";
	// createNode(q);

	// cout << "The two is has same structure? " << structureCmp(p, q) << endl;

	cout << "If the tree is a balanced tree? " << isAVLTree(p) << endl;

	Node *listStart, *listEnd;
	convertDoubleLinkedNode(p, listStart, listEnd);

	cout << "convertDoubleLinkedNode: ";
	while (listStart) {
		cout << listStart->val << " ";
		listStart = listStart->right;
	}
	cout << endl;

	return 0;
}