/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
	TreeNode *buildTreeHelper(vector<int> &inorder, int i_start, int i_end,
							vector<int> &postorder, int p_start, int p_end) {
		if (i_end <= i_start) {
			return NULL;
		}
		int root_val = postorder[p_end - 1];
		TreeNode *root = new TreeNode(root_val);
		int root_posi = i_start;
		for (; inorder[root_posi] != root_val; root_posi++) {
			;
		}
		root->left = buildTreeHelper(inorder, i_start, root_posi, postorder, p_start, p_start + root_posi - i_start);
		root->right = buildTreeHelper(inorder, root_posi+1, i_end, postorder, p_start + root_posi - i_start, p_end - 1);
	}

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int len = inorder.size();
		return buildTreeHelper(inorder, 0, len, postorder, 0, len);        
    }
};
