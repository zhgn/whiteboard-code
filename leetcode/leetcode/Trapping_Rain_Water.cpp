/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 
For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
*/

#include "stdafx.h"
#include <stack>

using namespace std;

class Solution {
private:
	int toward_highest_trap(int A[], int start, int end, int step) {
		int wall = 0;
		int water_sum = 0;
		for (int i=start; i!=end; i+=step) {
			if (A[i] > wall) {
				wall = A[i];
			} else {
				water_sum += wall - A[i];
			}
		}
		return water_sum;
	}

public:
    int trap(int A[], int n) {
		if (n == 0) {
			return 0;
		}

		int highest = -1;
		int highest_pos = -1;		
		for (int i=0; i<n; i++) {
			if (highest < A[i]) {
				highest = A[i];
				highest_pos = i;
			}
		}
		return (toward_highest_trap(A, 0, highest_pos, 1) + toward_highest_trap(A, n-1, highest_pos, -1));
    }
};
