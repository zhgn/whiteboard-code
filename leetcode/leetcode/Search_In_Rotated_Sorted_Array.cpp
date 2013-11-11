/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
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