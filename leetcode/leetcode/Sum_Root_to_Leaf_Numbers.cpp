/* Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,
    1
   / \
  2   3


 The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13.

 Return the sum = 12 + 13 = 25.
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
    void sumNumbersHelper(TreeNode *root, int cur_prefix, int &cur_sum) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            cur_sum += cur_prefix * 10 + root->val;
            return;
        }
        sumNumbersHelper(root->left, cur_prefix*10 + root->val, cur_sum);
        sumNumbersHelper(root->right, cur_prefix*10 + root->val, cur_sum);
    }

    int sumNumbers(TreeNode *root) {
        int sum = 0;
        sumNumbersHelper(root, 0, sum);
        
        return sum;
    }
};

