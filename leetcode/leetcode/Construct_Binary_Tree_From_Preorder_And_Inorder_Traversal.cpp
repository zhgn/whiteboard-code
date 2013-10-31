/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
 You may assume that duplicates do not exist in the tree. 
*/

#include "stdafx.h"
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode *buildTreeHelper(vector<int> &preorder, int p_start, int p_end,
							vector<int> &inorder, int i_start, int i_end) {
		if (i_end <= i_start) {
			return NULL;
		}
		int root_val = preorder[p_start];
		TreeNode *root = new TreeNode(root_val);
		int root_posi = i_start;
		for (; inorder[root_posi] != root_val; root_posi++) {
			;
		}
		root->left = buildTreeHelper(preorder, p_start + 1, p_start + 1 + root_posi - i_start, inorder, i_start, root_posi);
		root->right = buildTreeHelper(preorder, p_start + 1 + root_posi - i_start, p_end, inorder, root_posi + 1, i_end);
	}

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int len = inorder.size();
		return buildTreeHelper(preorder, 0, len, inorder, 0, len);        
    }
};
