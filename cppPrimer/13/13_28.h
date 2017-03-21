#include <string>

using namespace std;

class TreeNode {
public:
	TreeNode() : value(string()), count(new int(1)), left(nullptr), right(nullptr) {}	
	TreeNode(const TreeNode &rhs) 
		: value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
	TreeNode &operator=(const TreeNode &);
	~TreeNode();

private:
	string value;
	int	*count;
	TreeNode *left;
	TreeNode *right;
};

TreeNode &
TreeNode::operator=(const TreeNode &rhs)
{
	++*rhs.count;
	if (--*count == 0) {
		if (left) {
			delete left;
			left = nullptr;
		}
		if (right) {
			delete right;
			right = nullptr;
		}
		delete count;
		count = nullptr;
	}

	value = rhs.value;
	count = rhs.count;
	left = rhs.left;
	right = rhs.right;

	return *this;
}

TreeNode::~TreeNode()
{
	if (--*count == 0) {
		if (left) {
			delete left;
			left = nullptr;
		}
		if (right) {
			delete right;
			right = nullptr;
		}
		delete count;
		count = nullptr;
	}
}

class BinStrTree {
public:
	BinStrTree() : root(new TreeNode()) {} 
	BinStrTree(const BinStrTree &cp) : root(new TreeNode(*cp.root)) {}
	BinStrTree &operator=(const BinStrTree &); 

	~BinStrTree() { delete root; }

private:
	TreeNode *root;
};

BinStrTree &
BinStrTree::operator=(const BinStrTree &cp)
{
	TreeNode *newRoot = new TreeNode(*cp.root);
	delete root;
	root = newRoot;

	return *this;
}