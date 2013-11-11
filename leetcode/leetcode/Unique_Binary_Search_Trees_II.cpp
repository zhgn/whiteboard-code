/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

 For example,
 Given n = 3, your program should return all 5 unique BST's shown below. 
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<TreeNode *> generateTrees(int start, int end) {
        vector<TreeNode *> ret;
        if (start > end) {
            ret.push_back(NULL);
            return ret;
        }
        for (int i_root=start; i_root<=end; i_root++) {            
            vector<TreeNode *> left = generateTrees(start, i_root-1);
            vector<TreeNode *> right = generateTrees(i_root+1, end);
            for (auto it_left = left.begin(); it_left != left.end(); it_left++) {
                for (auto it_right = right.begin(); it_right != right.end(); it_right++) {
                    TreeNode *root = new TreeNode(i_root);
                    root->left = *it_left;
                    root->right = *it_right;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }

public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }
};
