/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 
For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
The contiguous subarray [4,?1,2,1] has the largest sum = 6. 

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/


#include "stdafx.h"

class Solution {
public:
    int maxSubArray(int A[], int n) {
		if (n == 0) {
			return 0;
		}
		int max_sub_array = A[0];
		int cur_max = 0;
		for (int i=0; i<n; i++) {
			cur_max += A[i];
			if (cur_max > max_sub_array) {
				max_sub_array = cur_max;
			}
			if (cur_max < 0) {
				cur_max = 0;
			}
		}
		return max_sub_array;
    }
};
