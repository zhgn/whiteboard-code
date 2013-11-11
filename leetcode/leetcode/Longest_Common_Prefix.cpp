/*
Write a function to find the longest common prefix string amongst an array of strings. 
*/

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {        
        if (strs.size() == 0)
        {
            return "";
        }
        int p = 0;
        bool same_letter = true;
        while (same_letter)
        {
            if (strs[0].empty() || strs[0].length()-1 < p)
            {
                break;
            }            
            char c = strs[0][p];
            for (int i=1; i<strs.size(); i++)
            {
                if (strs[i].empty() || strs[i].length()-1 < p)
                {
                    same_letter = false;
                    break;
                }
                if (strs[i][p] != c)
                {
                    same_letter = false;
                    break;
                }
            }
            if (same_letter)
            {
                p++;
            }
        }
        return strs[0].substr(0,p); 
    }
};