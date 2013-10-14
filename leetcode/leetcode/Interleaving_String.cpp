/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2. 

For example,
 Given:
 s1 = "aabcc",
 s2 = "dbbca", 

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. 
*/

#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		int len_3 = s3.length();
        int len_1 = s1.length();
        int len_2 = s2.length();
        if (len_3 != len_1+len_2)
        {
            return false;
        }
        vector<vector<bool> > is_interleave (len_3+1, vector<bool>(len_1+1, false));
        
        is_interleave[0][0] = true;
        for (int i=1;i<=len_3;i++)
        {
            for (int j=0;j<=len_1 && j<=i; j++)
            {                
                if ((i>j) && i-j<=len_2 && is_interleave[i-1][j] && s3[i-1] == s2[i-j-1])
                {
                    is_interleave[i][j] = true;
                }
                if ((j>0) && is_interleave[i-1][j-1] && s3[i-1] == s1[j-1])
                {
                    is_interleave[i][j] = true;
                }                
            }
        }
        return is_interleave[len_3][len_1];
    }		
};
