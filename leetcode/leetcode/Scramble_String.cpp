/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 
Below is one possible representation of s1 = "great": 
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 
To scramble the string, we may choose any non-leaf node and swap its two children.
 
For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
     rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
 
We say that "rgeat" is a scrambled string of "great". 

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
     rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
 
We say that "rgtae" is a scrambled string of "great". 

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class Solution {    
public:
    bool isScramble(string s1, string s2) {
        // isValid[len][i][j] : in s1 start from i, in s2 start from j, length is len
        int len = s1.length();
        vector<vector<vector<bool> > > is_valid (len+1, vector<vector<bool> > (len, vector<bool> (len, false)));
        for (int k=1; k<=len; k++) {
            for (int i=0; i+k<=len; i++) {
                for (int j=0; j+k<=len; j++) {
                    if (s1.substr(i,k) == s2.substr(j,k)) {
                        is_valid[k][i][j] = true;
                        continue;
                    }
                    for (int cut=1; cut<k; cut++) {
                        if ((is_valid[cut][i][j+k-cut] && is_valid[k-cut][i+cut][j]) || (is_valid[cut][i][j] && is_valid[k-cut][i+cut][j+cut])) {
                            is_valid[k][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return is_valid[len][0][0];
    }
};
