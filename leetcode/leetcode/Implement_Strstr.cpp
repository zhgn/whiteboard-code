/*
Implement strStr(). 

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/

#include "stdafx.h"
#include <vector>

using namespace std;

//KMP
class Solution {
private:
	vector<int> jump_table;

	void build_jump_table(char *s) {
		jump_table.clear();
		jump_table.push_back(-1);

		int longest = 0;
		for (int i=1; s[i] != '\0'; i++) {
			if (s[longest] == s[i]) {
				jump_table.push_back( longest++ );
			} else {
				while (longest != -1) {
					longest = jump_table[longest];
					if (s[longest+1] == s[i]) {
						jump_table.push_back( ++longest );
						break;
					}
				}
				if (longest == -1) {
					jump_table.push_back( longest++ );
				}
			}
		}
	}

public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL || needle[0] == '\0') {
			return haystack;
		}
		build_jump_table(needle);

		int i=0;
		int j=0;
		while (haystack[i] != '\0') {
			if (haystack[i] == needle[j]) {
				i++;
				j++;
				if (needle[j] == '\0') {
					return haystack + i - j;
				}
			} else {
				while (j != 0 && haystack[i] != needle[j]) {
					j = jump_table[j-1] + 1;
				}
				if (haystack[i] != needle[j]) {
					i++;
				}
			}			
		}
		return NULL;
    }
};
