/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        int min_diff = INT_MAX;
        int result = 0;
        sort(num.begin(), num.end());
        for (int i=0; i<n; i++)
        {
            for (int j=i+1,k=n-1; j<k; )
            {
                int diff = num[i] + num[j] + num[k] - target;
                if (abs(diff)<min_diff)
                {
                    min_diff = abs(diff);
                    result = num[i] + num[j] + num[k];
                }
                if (diff > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return result;
    }    
};
