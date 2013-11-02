/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include "stdafx.h"
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    bool is_pair(char left, char right) {
        return ((left == '(' && right == ')') 
            || (left == '[' && right == ']')
            || (left == '{' && right == '}'));
    }

public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if ((!st.empty()) && is_pair(st.top(), s[i])) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
