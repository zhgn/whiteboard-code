/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:
 'A' -> 1
'B' -> 2
...
'Z' -> 26

 Given an encoded message containing digits, determine the total number of ways to decode it.
 
For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12). 

The number of ways decoding "12" is 2. 
*/

#include "stdafx.h"
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();        
        if (n == 0 || s[0] == '0')
            return 0;               
        int a = 1;
        int b = 1;
        for (int i=1; i<n; i++)
        {
            int cur = 0;
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] - '0' <= 6))
            {
                cur+=a;
            }
            if (s[i] != '0')
            {
                cur+=b;
            }
            a = b;
            b = cur;            
        }
        return b;
    }
};
