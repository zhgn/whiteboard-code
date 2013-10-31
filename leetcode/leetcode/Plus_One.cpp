/*
Given a number represented as an array of digits, plus one to the number.
*/

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		int len = digits.size();
        int i = len - 1; 
		while (i>=0 && digits[i] == 9) {
			digits[i] = 0;
			i--;
		}
		if (i < 0) {
			digits[0] = 1;
			digits.push_back(0);
		} else {
			digits[i]++;
		}
		return digits;
    }
};
