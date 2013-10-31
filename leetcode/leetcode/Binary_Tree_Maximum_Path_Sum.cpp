/* Given a binary tree, find the maximum path sum. 

The path may start and end at any node in the tree. 

For example:
 Given the below binary tree, 
       1
      / \
     2   3
 

Return 6. 
*/

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
public:
	static const int Minimum = -(1 << 29);

	void maxPathSumHelper(TreeNode *root, int &max_sum, int &max_chain_with_root_end) {
		if (root == NULL) {
			return;
		}
		int left_max_sum = Minimum;
		int left_max_chain = Minimum;
		if (root->left != NULL) {
			maxPathSumHelper(root->left, left_max_sum, left_max_chain);
		}
		int right_max_sum = Minimum;
		int right_max_chain = Minimum;
		if (root->right != NULL) {
			maxPathSumHelper(root->right, right_max_sum, right_max_chain);
		}

		if (max_chain_with_root_end < left_max_chain + root->val)
			max_chain_with_root_end = left_max_chain + root->val;
		if (max_chain_with_root_end < right_max_chain + root->val)
			max_chain_with_root_end = right_max_chain + root->val;
		if (max_chain_with_root_end < root->val)
			max_chain_with_root_end = root->val; 

		if (max_sum < left_max_sum) 
			max_sum = left_max_sum;
		if (max_sum < right_max_sum)
			max_sum = right_max_sum;
		if (max_sum < max_chain_with_root_end)
			max_sum = max_chain_with_root_end;
		if (max_sum < left_max_chain + right_max_chain + root->val)
			max_sum = left_max_chain + right_max_chain + root->val;
	}

    int maxPathSum(TreeNode *root) {
        int max_sum = Minimum;
		int max_chain_with_root_end = Minimum;
		maxPathSumHelper(root, max_sum, max_chain_with_root_end);
		return max_sum;
    }
};