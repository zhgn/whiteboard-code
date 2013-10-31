/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 
For "(()", the longest valid parentheses substring is "()", which has length = 2.
 
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#include "stdafx.h"
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack <int> st;
        int re = 0;        
        int fail_pos = 0;
        for (int i=0; i<n; i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if (!st.empty())
                {
                    st.pop();
                    int start = st.empty() ? fail_pos-1 : st.top();
                    if (i - start > re)
                    {
                        re = i - start;
                    }
                }
                else
                {
                    fail_pos = i + 1;
                }
            }
        }
        return re;
    }
};