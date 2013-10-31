/*
Given a binary tree, determine if it is height-balanced. 

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */

#include "stdafx.h"
#include <algorithm>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool heightAndIsBalanced(TreeNode *root, int &height) {
		if (root == NULL) {
			return true;
		}
		int left_height = 0;
		int right_height = 0;
		bool child_balanced = (heightAndIsBalanced(root->left, left_height) && heightAndIsBalanced(root->right, right_height));
		height = std::max(left_height, right_height) + 1;
		return ((child_balanced) && (std::abs(left_height - right_height) <= 1));
	}

public:
    bool isBalanced(TreeNode *root) {
		int height = 0;
        return heightAndIsBalanced(root, height);
    }
};
