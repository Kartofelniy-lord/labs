#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree() {
	root = nullptr;
}

BinaryTree::BinaryTree(int value) {
	root->setKey(0);
}

BinaryTree::~BinaryTree() {
	destroyTree();
}

void BinaryTree::destroyTree() {
	destroyTree(root);
}

void BinaryTree::destroyTree(TreeNode *node) {
	if (node != nullptr) {
		destroyTree(node->getLeft());
		destroyTree(node->getRight());
		delete node;
	}
}

void BinaryTree::insert(int val) {
	if (root != nullptr) {
		insert(val, root);
	}
	else {
		root = new TreeNode();
		root->setKey(val);
		root->setLeft(nullptr);
		root->setRight(nullptr);
	}
}

void BinaryTree::insert(int val, TreeNode *node) {
	if (val < node->getKey()) {
		if (node->getLeft() != nullptr) {
			insert(val, node->getLeft());
		}
		else
		{
			node->setLeft(new TreeNode());
			node->getLeft()->setKey(val);
			node->getLeft()->setLeft(nullptr);
			node->getLeft()->setRight(nullptr);
		}
	}
	else if (val >= node->getKey()) {
		if (node->getRight() != nullptr) {
			insert(val, node->getRight());
		}
		else {
			node->setRight(new TreeNode());
			node->getRight()->setKey(val);
			node->getRight()->setLeft(nullptr);
			node->getRight()->setRight(nullptr);
		}
	}
}

TreeNode* BinaryTree::search(int value) {
	return search(value, root);
}

TreeNode* BinaryTree::search(int value, TreeNode *node) {
	if (node != nullptr) {
		if (value == node->getKey()) {
			return node;
		}
		if (value < node->getKey()) {
			search(value, node->getLeft());
		}
		else {
			search(value, node->getRight());
		}
	}
	else {
		return nullptr;
	}
}

void BinaryTree::inorderPrint() {
	inorderPrint(root);
	cout << "\n";
}

void BinaryTree::inorderPrint(TreeNode *node) {
	if (node != nullptr) {
		inorderPrint(node->getLeft());
		cout << node->getKey() << ", ";
		inorderPrint(node->getRight());
	}
}


