#pragma once
class TreeNode
{
private:
	int key = 0;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
public:
	TreeNode();
	TreeNode(int value);

	int getKey();
	void setKey(int value);

	TreeNode* getLeft();
	void setLeft(TreeNode* node);

	TreeNode* getRight();
	void setRight(TreeNode* node);

};

