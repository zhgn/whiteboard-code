/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
		if (root == NULL){
			return 0;
		}
		if (root->left == NULL && root->right == NULL) {
			return 1;
		}
		int depth = 1 << 30;
		if (root->left != NULL) {
			depth = minDepth(root->left) + 1;
		}
		if (root->right != NULL) {
			depth = std::min(depth, minDepth(root->right) + 1);
		}
		return depth;
    }
};
