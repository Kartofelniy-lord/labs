#include "TreeNode.h"

using namespace std;

TreeNode::TreeNode() {
	key = 0;
	left = nullptr;
	right = nullptr;
}

TreeNode::TreeNode(int value) {
	key = value;
	left = nullptr;
	right = nullptr;
}

int TreeNode::getKey() {
	return key;
}

void TreeNode::setKey(int value) {
	key = value;
}

TreeNode* TreeNode::getLeft() {
	return left;
}

void TreeNode::setLeft(TreeNode* node) {
	left = node;
}

TreeNode* TreeNode::getRight() {
	return right;
}

void TreeNode::setRight(TreeNode* node) {
	right = node;
}