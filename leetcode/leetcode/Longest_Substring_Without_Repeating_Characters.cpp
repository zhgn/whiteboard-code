/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include "stdafx.h"
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int occr[26];
        for (int i=0; i<26; i++) {
            occr[i] = 0;
        }
        int n = s.length();
        int max_len = 0;
        int start = 0;
        for (int i=0; i<n; i++) {
            int x = s[i] - 'a';
            if (occr[x] > start) {
                start = occr[x];
            }
            max_len = max(max_len, i - start + 1);                            
            occr[x] = i+1;
        }
        return max_len;
    }
};
