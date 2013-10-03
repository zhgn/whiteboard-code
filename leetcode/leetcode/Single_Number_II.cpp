/*
Given an array of integers, every element appears three times except for one. Find that single one.
 
Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 
*/

#include "stdafx.h"
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
	void addDigits(vector<int> &digits, unsigned int x) {
		int i=0;
		while (x) {
			digits[i] = (digits[i] + (x&1)) % 3;
			i++;
			x>>=1;
		}
	}

public:
    int singleNumber(int A[], int n) {
        vector<int> digits(32,0);
        for (int i=0; i<n; i++) {
			unsigned int tmp = *((unsigned int*)(A+i));
			addDigits(digits, tmp);
		}
		unsigned int single_number = 0;
		for (int i=31; i>=0; i--) {
			single_number = (single_number << 1) | digits[i];
		}
		return *((int *)(&single_number));
    }
};