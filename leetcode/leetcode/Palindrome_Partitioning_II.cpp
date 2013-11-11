/*
 Given a string s, partition s such that every substring of the partition is a palindrome.

 Return the minimum cuts needed for a palindrome partitioning of s.

 For example, given s = "aab",
 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
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

    int minCut(string s) {        
        int s_len = s.length();        
        if (s_len == 0) {
            return 0;
        }

        vector<int> min_cut_rec (s_len+1, s_len);
        vector<vector<bool>> is_palindrome (s_len, vector<bool> (s_len+1, true));
        prepareIsPalindrome(s, is_palindrome);
        min_cut_rec[0] = 0;

        for (int end = 1; end <= s_len; end++) {
            for (int start = 0; start < end; start++) {
                if (is_palindrome[start][end] && min_cut_rec[end] > min_cut_rec[start] + 1) {
                    min_cut_rec[end] = min_cut_rec[start] + 1;
                }
            }
        }        
        return min_cut_rec[s_len] - 1;
    }
};
