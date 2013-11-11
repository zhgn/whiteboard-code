/*
Given an array of integers, every element appears twice except for one. Find that single one.

 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include "stdafx.h"
#include <algorithm>

class Solution {
public:
    int singleNumber(int A[], int n) {  
        int single_number = 0;
        for (int i=0; i<n; i++) {
            single_number ^= A[i];
        }
        return single_number;
    }
};