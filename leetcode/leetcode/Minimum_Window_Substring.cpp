/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 
For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 

Minimum window is "BANC". 

Note:
 If there is no such window in S that covers all characters in T, return the emtpy string "".
 
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        vector<int> s (256, 0);
        vector<int> c (256, 0);
        int n = S.length();
        int m = T.length();
        int total_c = 0;
        for (int i=0; i<m; i++)
        {
            if (s[T[i]]==0)
            {
                total_c++;
            }
            s[T[i]]++;
        }
        int count = 0;
        int start = 0;
        int min = n+1;
        int rec_start = 0;
        int i=0;
        for (; i<n && count < total_c; i++)
        {
            c[S[i]]++;    
            if (c[S[i]] == s[S[i]])
            {
                count++;                
            }
        }
        if (count == total_c)
        {
            while (c[S[start]] > s[S[start]])
            {
                c[S[start]]--;
                start++;
            }       
            min = i-start;
            rec_start = start;
        } 
        for (;i<n;i++)
        {
            c[S[i]]++;
            while (c[S[start]] > s[S[start]])
            {
                c[S[start]]--;
                start++;
            }
            if (i-start+1 < min)                    
            {
                min = i-start+1;
                rec_start = start;
            }
        }
        if (min == n+1)
        {
            return "";
        }
        else
        {
            return S.substr(rec_start, min);
        }
    }
};
