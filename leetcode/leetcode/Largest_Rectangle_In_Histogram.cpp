/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.
 

For example,
 Given height = [2,1,5,6,2,3],
 return 10. 

*/

#include "stdafx.h"
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        stack<pair<int, int> > r;
        int result = 0;
        for (int i=0; i<n; i++)
        {
            if (r.empty() || height[i] >= r.top().second)
            {
                r.push(make_pair(i, height[i]));      
            }
            else
            {
                int left = 0;
                while (!r.empty() && height[i] < r.top().second)
                {
                    if ((i-r.top().first)*r.top().second > result)
                    {
                        result = (i-r.top().first)*r.top().second;
                    }
                    left = r.top().first;
                    r.pop();
                }                
                r.push(make_pair(left, height[i]));
            }
        }
        while (!r.empty())
        {
            while (!r.empty())
            {
                if ((n-r.top().first)*r.top().second > result)
                {
                    result = (n-r.top().first)*r.top().second;
                }
                r.pop();
            }   
        }      
        return result;          
    }
};
