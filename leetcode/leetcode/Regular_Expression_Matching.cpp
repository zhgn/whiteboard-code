/*
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "a*") ¡ú true
isMatch("aa", ".*") ¡ú true
isMatch("ab", ".*") ¡ú true
isMatch("aab", "c*a*b") ¡ú true
*/

#include "stdafx.h"

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p != '\0')
        {
            if (*(p+1) != '\0')
            {
                if (*(p+1) == '*')
                {
                    if (isMatch(s, p+2))
                    {
                        return true;
                    }
                    for (int i=0; *(s+i) != '\0'; i++)
                    {
                        if (*(s+i) == *p || *p == '.')
                        {
                            if (isMatch(s+i+1, p+2))
                            {
                                return true;
                            }
                        }
                        else
                        {
                            return false;
                        }
                    }
                    return false;
                }
                else
                {
                    if (*s == *p || (*p == '.' && *s != '\0'))
                    {
                        return isMatch(s+1, p+1);
                    }
                    return false;
                }
            }
            else
            {
                return ((*p == '.' || *p == *s) && (*s != '\0') && (*(s+1) == '\0'));
            }
        }
        else
        {
            return (*s == '\0');
        }
    }
};
