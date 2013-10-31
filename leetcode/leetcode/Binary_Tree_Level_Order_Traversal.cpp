/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
 
    3
   / \
  9  20
    /  \
   15   7
 

return its level order traversal as:
 
[
  [3],
  [9,20],
  [15,7]
]
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
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > all_vals;
		if (root == NULL) {
			return all_vals;
		}
		vector<TreeNode *> prev_level_nodes;
		vector<TreeNode *> cur_level_nodes;		
		vector<int> cur_level_vals;

		cur_level_nodes.push_back(root);
		cur_level_vals.push_back(root->val);
				
		while (cur_level_nodes.size() != 0) {
			all_vals.push_back(cur_level_vals);
			cur_level_vals.clear();
			prev_level_nodes = cur_level_nodes;
			cur_level_nodes.clear();
			
			for (int i=0; i<prev_level_nodes.size(); i++) {
				if (prev_level_nodes[i]->left != NULL) {
					cur_level_nodes.push_back(prev_level_nodes[i]->left);
					cur_level_vals.push_back(prev_level_nodes[i]->left->val);
				}
				if (prev_level_nodes[i]->right != NULL) {
					cur_level_nodes.push_back(prev_level_nodes[i]->right);
					cur_level_vals.push_back(prev_level_nodes[i]->right->val);
				}
			}
		}
        return all_vals;
    }
};