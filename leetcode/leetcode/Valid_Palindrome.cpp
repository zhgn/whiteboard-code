/* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 
For example,
 "A man, a plan, a canal: Panama" is a palindrome.
 "race a car" is not a palindrome. 

Note:
 Have you consider that the string might be empty? This is a good question to ask during an interview.
 
For the purpose of this problem, we define empty string as valid palindrome. 
*/

#include "stdafx.h"
#include <string>

using namespace std;

class Solution {
public:
	bool isNotAlphanumeric(char c) {
		return !((c >= 'a' && c <= 'z') || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9')));
	}

	char toUpr(char c) {
		if ((c >= 'a') && (c <= 'z')) {
			return c - 'a' + 'A';
		}
		return c;
	}

	bool equal(char x, char y) {
		return (toUpr(x) == toUpr(y));
	}

    bool isPalindrome(string s) {
		int len = s.length();
		for (int i=0,j=len-1; i<j; i++,j--) {
			while (isNotAlphanumeric(s[i]) && i<j) {
				i++;
			}
			while (isNotAlphanumeric(s[j]) && i<j) {
				j--;
			}
			if (!equal(s[i], s[j])) {
				return false;
			}
		}
		return true;
    }
};