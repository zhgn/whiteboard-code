/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 
Note: You may not slant the container. 
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        if (n <= 1) {
            return 0;
        }
        int area = 0;
        for (int i=0, j=n-1; i<j;)
        {
            int s = 0;

            if (height[i] < height[j])
            {
                s = height[i] * (j - i);
                i++;
            }
            else
            {
                s = height[j] * (j - i);
                j--;
            }
            if (s > area)
            {
                area = s;
            }            
        }
        return area;
    }
};
