/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

 For example, 
Given s = "Hello World",
 return 5. 
*/

#include "stdafx.h"

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        while (s[len] != '\0') {
            len++;
        }
        while (len > 0 && s[len - 1] == ' ') {
            len--;
        }
        int last_space = len - 1;
        while (last_space >= 0 && s[last_space] != ' ') {
            last_space--;
        }
        return len - last_space - 1;
    }
};
