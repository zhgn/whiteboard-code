/*
Given a binary tree, return the postorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
 
   1
    \
     2
    /
   3
 

return [3,2,1]. 

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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> ret;

        if (root == NULL) {
            return ret;
        }
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            TreeNode *left = cur->left;
            TreeNode *right = cur->right;
            if (left == NULL && right == NULL) {
                ret.push_back(cur->val);
            } else {
                cur->left = NULL;
                cur->right = NULL;
                st.push(cur);
                if (right != NULL) {
                    st.push(right);
                }
                if (left != NULL) {
                    st.push(left);
                }
            }
        }
        return ret;
    }
};
