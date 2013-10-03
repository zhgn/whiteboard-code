/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 For example:
 Given the below binary tree and sum = 22,               5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

 return
 
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

#include "stdafx.h"
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
	vector<vector<int> > AllPath;

	void pathSumHelper(TreeNode *root, vector<int> &path, int sum) {
		if (root == NULL) {
			return;
		}
		sum -= root->val;
		path.push_back(root->val);
		if (sum == 0 && root->left == NULL && root->right == NULL) {
			AllPath.push_back(path);			
		}
		pathSumHelper(root->left, path, sum);
		pathSumHelper(root->right, path, sum);
		path.pop_back();		
	}

public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
		AllPath.clear();    
		vector<int> path;
        pathSumHelper(root, path, sum);
		return AllPath;
    }
};
