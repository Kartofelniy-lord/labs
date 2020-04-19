#include "BinaryTree.h"
#include "TreeNode.h"

using namespace std;

int main() {
	BinaryTree *tree = new BinaryTree();
	
	tree->insert(3);
	tree->insert(4);
	tree->insert(11);
	tree->insert(42);
	tree->insert(45);
	tree->insert(9);
	tree->insert(10);

	tree->inorderPrint();
}


