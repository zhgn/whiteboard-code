/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string ret;
        int len1 = num1.length();
        int len2 = num2.length();
        vector<int> x (len1+len2, 0);
        for (int i=0; i<len1; i++)
        {
            for (int j=0; j<len2; j++)
            {
                x[i+j] += (num1[len1-i-1] - '0')*(num2[len2-j-1] - '0');
            }            
        }
        for (int i=0; i<len1+len2; i++)
        {
            x[i+1] += x[i] / 10;
            x[i] %= 10;    
        }
        int len = len1 + len2 - 1;
        while (x[len] == 0 && len>0)
        {
            len--;
        }
        for (int i=len; i>=0; i--)
        {
            ret.append(1, x[i] + '0');
        }
        return ret;
    }
};

