/*
Given a binary tree, determine if it is a valid binary search tree (BST). 

Assume a BST is defined as follows: 
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

#include "stdafx.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool isValidBSTHelper(TreeNode *root, TreeNode *&prev) {
		if (root == NULL) {
			return true;
		}		
		if ( ! isValidBSTHelper(root->left, prev)) {
			return false;
		}
		if (prev != NULL && prev->val >= root->val) {
			return false;			
		}
		prev = root;
		return isValidBSTHelper(root->right, prev);			
	}

public:
    bool isValidBST(TreeNode *root) {
		TreeNode *prev = NULL;
		return isValidBSTHelper(root, prev);
    }
};