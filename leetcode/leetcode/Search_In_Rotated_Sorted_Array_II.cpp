/*
Follow up for "Search in Rotated Sorted Array":
 What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

#include "stdafx.h"

class Solution {
private:
	int binary_search(int A[], int low, int high, int target) {
		if (low >= high) {
			return -1;
		}
		int mid = (low + high) / 2;
		if (target == A[mid]) {
			return mid;
		}
		if (A[low] == A[mid]) {
			return binary_search(A, low+1, high, target);
		}
		if (A[low] < A[mid]) {
			if (A[low] > target || A[mid] < target) {
				return binary_search(A, mid+1, high, target);
			} else {
				return binary_search(A, low, mid, target);
			}
		} else {
			if (A[mid] < target && A[high-1] >= target) {
				return binary_search(A, mid+1, high, target);
			} else {
				return binary_search(A, low, mid, target);
			}
		}
	}

public:
    int search(int A[], int n, int target) {
        return binary_search(A, 0, n, target);        
    }
};
