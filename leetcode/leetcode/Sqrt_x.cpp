/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

#include "stdafx.h"

class Solution {
public:
    int sqrt(int x) {
		if (x <= 1) {
			return x;
		}
        int low = 1;
		int high = x-1;
        while (high - low > 1) {
			int mid = (low + high) / 2;
			if ((long long)mid * mid <= x) {
				low = mid;
			} else {
				high = mid;
			}
		}
		return low;
    }
};
