/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 
For example, given n = 3, a solution set is: 

"((()))", "(()())", "(())()", "()(())", "()()()" 
*/

#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0)
            return result;
        if (n == 1)
        {
            result.push_back("()");
            return result;
        }            
        vector<string> tmp = generateParenthesis(n-1);
        for (int i=0; i<tmp.size(); i++)
        {
            int count = 0;
            int len = 2*n-2;
            for (int j=0; j<len; j++)
            {
                if (count == 0)
                {
                    result.push_back(tmp[i].substr(0,j) + "(" + tmp[i].substr(j,len-j) + ")");
                }
                if (tmp[i][j] == '(')
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
            result.push_back(tmp[i] + "()");
        }
        return result;
    }
};
