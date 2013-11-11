/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note:
 You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/

#include "stdafx.h"


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for (int i=m+n-1, i_a = m-1, i_b = n-1; i>=0; i--) {
            if (i_a < 0) {
                A[i] = B[i_b--];
            } else if (i_b < 0) {
                A[i] = A[i_a--];
            } else if (A[i_a] < B[i_b]) {
                A[i] = B[i_b--];
            } else {
                A[i] = A[i_a--];
            }
        }                    
    }
};
