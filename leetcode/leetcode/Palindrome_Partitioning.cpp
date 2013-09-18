/* Given a string s, partition s such that every substring of the partition is a palindrome.

 Return all possible palindrome partitioning of s.

 For example, given s = "aab",
 Return
  [
    ["aa","b"],
    ["a","a","b"]
  ]
 */

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	//Notice: Call by Reference
	void prepareIsPalindrome(string s, vector<vector<bool>>& is_palindrome) {
		int s_len = s.length();
		for (int len = 2; len <= s_len; len++) {
			for (int start = 0; start + len <= s_len; start++) {			
				is_palindrome[start][start+len] = ((s[start] == s[start+len-1]) && (is_palindrome[start+1][start+len-1]));
			}
		}		
	}

	vector<vector<string>> partitionHelper(string s, int start, int end, vector<vector<bool>> is_palindrome) {		
		vector<vector<string>> all_partitions;
		vector<vector<string>> sub_results;
		for (int posi = start+1; posi < end; posi++) {
			if (is_palindrome[posi][end]) {
				sub_results = partitionHelper(s, start, posi, is_palindrome);
				for (int i=0; i<sub_results.size(); i++) {
					vector<string> tmp = sub_results[i];
					tmp.push_back(s.substr(posi, end-posi));
					all_partitions.push_back(tmp);
				}
			}
		}
		if (is_palindrome[start][end]) {
			vector<string> tmp;
			tmp.push_back(s.substr(start,end-start));
			all_partitions.push_back(tmp);
		}
		return all_partitions;
	}

    vector<vector<string>> partition(string s) {		
		int s_len = s.length();		
		vector<vector<bool>> is_palindrome (s_len, vector<bool> (s_len+1, true));
		prepareIsPalindrome(s, is_palindrome);	

		return partitionHelper(s, 0, s_len, is_palindrome);	
    }
};
