/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 
For example, given
 s = "leetcode",
 dict = ["leet", "code"]. 

Return true because "leetcode" can be segmented as "leet code". 
*/

#include "stdafx.h"
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
		int s_len = s.length();
		vector<bool> could_break (s_len+1, false);
		could_break[0] = true;
		for (int i=0; i<s_len; i++) {
			if (could_break[i]) {
				for (int j=i+1; j<=s_len; j++) {
					if (dict.end() != dict.find(s.substr(i,j-i))) {
						could_break[j] = true;
					}
				}
			}
		}
        return could_break[s_len];
    }
};