/*
Implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "*") �� true
isMatch("aa", "a*") �� true
isMatch("ab", "?*") �� true
isMatch("aab", "c*a*b") �� false
*/

#include "stdafx.h"

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        bool star = false;
		const char *p_after_star = NULL;
		const char *match_with_star = NULL;
		while (*s != '\0') {
			if (*p == '*') {
				star = true;				
				p++;					
				p_after_star = p;
				match_with_star = s;
			} else if (*p == '?' || *p == *s) {
				s++;
				p++;				
			} else if (star) {
				p = p_after_star;
				s = ++match_with_star;				
			} else {
				return false;
	        }
		}
        while (*p == '*') {
			p++;
		}
		return (*p == '\0');
    }
};
