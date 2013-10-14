/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
public:
    int maxDepth(TreeNode *root) {
		if (root == NULL){
			return 0;
		}
		if (root->left == NULL && root->right == NULL) {
			return 1;
		}
		int depth = 0;
		if (root->left != NULL) {
			depth = maxDepth(root->left) + 1;
		}
		if (root->right != NULL) {
			depth = std::max(depth, maxDepth(root->right) + 1);
		}
		return depth;
    }
};
