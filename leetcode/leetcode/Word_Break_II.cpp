/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 
Return all such possible sentences. 

For example, given
 s = "catsanddog",
 dict = ["cat", "cats", "and", "sand", "dog"]. 

A solution is ["cats and dog", "cat sand dog"]. 

*/

#include "stdafx.h"
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
	vector<string> results;

	void makeResults(string &s, vector<vector<int> > &prev_break_posi, int cur_posi, string &cur_s) {
		if (cur_posi == 0) {
			results.push_back(cur_s.substr(1));
			return;
		}		
		for (int i=prev_break_posi[cur_posi].size()-1; i>=0; i--) {
			int break_posi = prev_break_posi[cur_posi][i];
			string next_s = s.substr(0, break_posi) + " " + cur_s.substr(break_posi);
			makeResults(s, prev_break_posi, break_posi, next_s);
		}
	}

public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
		results.clear();
		int s_len = s.length();
		vector<vector<int> > prev_break_posi (s_len+1, vector<int> ());
		vector<bool> could_break (s_len+1, false);
		could_break[0] = true;
		
		for (int i=0; i<s_len; i++) {
			if (could_break[i]) {
				for (int j=i+1; j<=s_len; j++) {
					if (dict.end() != dict.find(s.substr(i,j-i))) {
						could_break[j] = true;
						prev_break_posi[j].push_back(i);
					}
				}
			}
		}
		
		string empty_str = s;
		makeResults(s, prev_break_posi, s_len, empty_str);
		return results;
    }
};
