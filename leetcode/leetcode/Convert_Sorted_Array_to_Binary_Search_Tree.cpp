/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *sortedArrayToBST(vector<int> &num, int start, int end) {
        if (start >= end) {
            return NULL;
        }
        int mid = (start + end)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST(num, start, mid);
        root->right = sortedArrayToBST(num, mid+1, end);
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size());        
    }
};