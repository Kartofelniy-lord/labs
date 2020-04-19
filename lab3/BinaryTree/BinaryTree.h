#pragma once
#include "TreeNode.h"
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(int value);
	~BinaryTree();

	void insert(int value);
	TreeNode* search(int value);
	void destroyTree();

	void inorderPrint();

private:
	void insert(int val, TreeNode* node);
	TreeNode* search(int value, TreeNode* node);
	void destroyTree(TreeNode* node);

	void inorderPrint(TreeNode* node);

	TreeNode *root;
};

