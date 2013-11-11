/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4]. 
*/


#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        if (n == 0 || A[0] > target) {
            return vector<int> (2, -1);
        }
        int start = 0;
        if (A[0] < target) {
            int low = 0;
            int high = n;
            while (low < high - 1) {
                int mid = (low + high) / 2;
                if (A[mid] >= target) {
                    high = mid;
                } else {
                    low = mid;
                }
            }            
            start = low + 1;
            if (start >= n || A[start] != target) {
                return vector<int> (2, -1);
            }
        }
        vector<int> ret;
        ret.push_back(start);
        int low = start;
        int high = n - 1;
        if (A[high] == target) {
            ret.push_back(high);
            return ret;
        }
        while (low < high - 1) {
            int mid = (low + high + 1) / 2;
            if (A[mid] > target) {
                high = mid;
            } else {
                low = mid;
            }
        }
        ret.push_back(high - 1);
        return ret;
    }
};