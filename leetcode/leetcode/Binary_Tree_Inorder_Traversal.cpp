/*
Given a binary tree, return the inorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
 
   1
    \
     2
    /
   3
 

return [1,3,2]. 

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include "stdafx.h"
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
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        
        if (root == NULL)
        {
            return result;
        }
        st.push(root);        
		while (!st.empty())
        {
			TreeNode *cur = st.top();
			st.pop();
            if (cur->left != NULL)
            {				
				TreeNode *left = cur->left;
				cur->left = NULL;
				st.push(cur);
				st.push(left);                
            }
            else
            {                                                
                result.push_back(cur->val);                
                if (cur->right != NULL)
                {
                    st.push(cur->right); 
                }                
            }
        }
        return result;	      
    }
};