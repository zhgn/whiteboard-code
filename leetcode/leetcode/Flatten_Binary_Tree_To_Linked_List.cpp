#include "stdafx.h"
#include <string>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode *flattenHelper(TreeNode *root) {
		if (root == NULL) {
			return NULL;
		}
		TreeNode *left_tail = flattenHelper(root->left);
		TreeNode *right_tail = flattenHelper(root->right);
		if (left_tail != NULL) {
			left_tail->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
		if (right_tail != NULL) {
			return right_tail;
		} else if (left_tail != NULL) {
			return left_tail;
		}
		return root;
	}

public:
    void flatten(TreeNode *root) {
        flattenHelper(root);
    }
};
