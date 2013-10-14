/*
Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?

 For example,
 Given sorted array A = [1,1,1,2,2,3], 

Your function should return length = 5, and A is now [1,1,2,2,3]. 
*/

#include "stdafx.h"

class Solution {
public:
    int removeDuplicates(int A[], int n) {		
		int remain = n < 2 ? n : 2;
		for (int index=2; index<n; index++) {
			if (A[index] != A[remain-2]) {
				A[remain++] = A[index];
			}
		}
        return remain;
    }
};
