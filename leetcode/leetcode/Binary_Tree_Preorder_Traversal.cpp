/*
Given a binary tree, return the preorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
 
   1
    \
     2
    /
   3
 

return [1,2,3]. 

Note: Recursive solution is trivial, could you do it iteratively?
*/


#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> ret;

        if (root == NULL) {
            return ret;
        }
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            ret.push_back(cur->val);            
            if (cur->right != NULL) {
                st.push(cur->right);
            }
            if (cur->left != NULL) {
                st.push(cur->left);
            }
        }
    }
};
