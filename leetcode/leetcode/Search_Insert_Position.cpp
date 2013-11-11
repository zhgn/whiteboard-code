/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

 Here are few examples.
 [1,3,5,6], 5 ¡ú 2
 [1,3,5,6], 2 ¡ú 1
 [1,3,5,6], 7 ¡ú 4
 [1,3,5,6], 0 ¡ú 0 
*/

#include "stdafx.h"

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0 || A[0] >= target) {
            return 0;
        }
        int low = 0;
        int high = n;        
        while (low < high - 1) {
            int mid = (low + high) / 2;
            if (A[mid] == target) {
                return mid;
            }
            if (A[mid] < target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return high;
    }
};
