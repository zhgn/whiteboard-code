/*
The set [1,2,3,бн,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3): 
1."123"
 2."132"
 3."213"
 4."231"
 5."312"
 6."321"
 

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        vector<bool> used (n, false);
        int total_num = 1;
        for (int i=0; i<n-1; i++)
        {
            total_num *= i+1;
        }
        for (int i=n-1; i>=0; i--)
        {
            int count = (k-1) / total_num + 1;
            int real_num = 0;
            for (int j=0; j<count; j++)
            {
                do
                {
                    real_num++;
                }while (used[real_num]);
            }
            result.append(1, '0' + (real_num));
            used[real_num] = true;
            k = (k-1) % total_num + 1;
            if (i > 0)
            {
                total_num /= i;
            }
        }
        return result;        
    }
};