/* Given a string S and a string T, count the number of distinct subsequences of T in S.
 
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 
Here is an example:
 S = "rabbbit", T = "rabbit" 

Return 3. 
*/

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
		int s_len = S.length();
		int t_len = T.length();
		vector<vector<int> > count(s_len+1, vector<int>(t_len+1, 0));
        
		for (int i=0; i<s_len; i++) {
			count[i][0] = 1;
		}
		for (int i=0; i<s_len; i++) {
			for (int j=0; j<t_len; j++) {
				count[i+1][j+1] = count[i][j+1];
				if (S[i] == T[j]) {
					count[i+1][j+1] += count[i][j];
				}
			}
		}
		return count[s_len][t_len];
    }
};
