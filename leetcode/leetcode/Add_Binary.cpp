/*
Given two binary strings, return their sum (also a binary string). 

For example,
 a = "11"
 b = "1"
 Return "100". 
*/

#include "stdafx.h"
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		int len_a = a.length();
		int len_b = b.length();
		int len_ret = max(len_a, len_b);
		string ret;		
		int plus = 0;
		for (int i=len_a-1, j=len_b-1; i>=0 || j>=0; i--, j--) {
			int val = plus;
			if (i >= 0) {
				val += a[i] - '0';
			}
			if (j >= 0) {
				val += b[j] - '0';
			}
			plus = val >> 1;			
			ret = (string(1, (val & 1) + '0')).append(ret);
		}
		if (plus > 0) {
			ret = "1" + ret;
		}
		return ret;
    }
};
