#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if (n == 0)
        {
            return "";
        }
        if (n == 1)
        {
            return s;
        }
        vector<vector<bool> > isPalindrome (n+1, vector<bool>(n+1, false));
        for (int i=0;i<n;i++)
        {
            isPalindrome[0][i] = true;
            isPalindrome[1][i] = true;
        }
        int mymax = 1;
        int start = 0;
        for (int len=2;len<=n;len++)
        {
            for (int i=1;i<=n-len+1;i++)
            {
                if (isPalindrome[len-2][i])
                {
                    if (s[i-1]==s[i+len-2])
                    {
                        isPalindrome[len][i-1] = true;
                        if (len > mymax)
                        {
                            mymax = len;
                            start = i-1;
                        }
                    }
                }
            }    
        }
        return s.substr(start,mymax);
    }
};

