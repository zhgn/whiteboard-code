/*
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/

#include "stdafx.h"

class Solution {
private:
    int kth_median(int A[], int m, int B[], int n, int k) {
        if (m > n) {
            return kth_median(B, n, A, m, k);
        }
        if (m == 0) {
            return B[k-1];
        }
        if (k == 1) {
            return A[0] < B[0] ? A[0] : B[0];
        }

        int pa = k / 2;
        if (pa > m) {
            pa = m;
        }
        int pb = k - pa;
        if (A[pa-1] < B[pb-1])
        {
            return kth_median(A+pa, m-pa, B, n, k-pa);
        }
        else
        {
            return kth_median(A, m, B+pb, n-pb, k-pb);
        }
    }

public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m+n;
        if (total & 0x1)
        {
            return kth_median(A, m, B, n, total/2+1);
        }
        return (kth_median(A, m, B, n, total/2) + kth_median(A, m, B, n, total/2+1)) * 0.5;
    }    
};
