/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

 For example, given the following triangle
 
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
 

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). 

Note:
 Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int rows_num = triangle.size();
        vector<int> min_path (rows_num, 0);
        for (int row=0; row<rows_num; row++) {            
            if (row>0) {
                min_path[row] = triangle[row][row] + min_path[row-1];
            }
            for (int column=row-1; column>0; column--) {
                min_path[column] = min(min_path[column], min_path[column-1]) + triangle[row][column];
            }
            min_path[0] = triangle[row][0] + min_path[0];
        }

        int result = 1 << 29;
        for (int column=0; column<rows_num; column++) {
            result = min(result, min_path[column]);
        }
        return result;
    }
};
