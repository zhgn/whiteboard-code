/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

 For example, this binary tree is symmetric: 
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
    bool isTheSame(TreeNode *root_a, TreeNode *root_b) {
        if (root_a == NULL && root_b == NULL) {
            return true;
        }
        if (root_a == NULL || root_b == NULL) {
            return false;
        }
        if (root_a->val != root_b->val) {
            return false;
        }
        return (isTheSame(root_a->left, root_b->right) && isTheSame(root_a->right, root_b->left));
    }

public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        return isTheSame(root->left, root->right);        
    }
};
