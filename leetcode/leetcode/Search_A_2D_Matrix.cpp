/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

 
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

For example,
 
Consider the following matrix: 
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

 Given target = 3, return true.
*/

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int row = matrix.size();
		if (row == 0) {
			return false;
		}
		int column = matrix[0].size();
		int x = column - 1;
		int y = 0;
		while (y < row && x >= 0 && target != matrix[y][x]) {
			if (target > matrix[y][x]) {
				y++;
			} else {
				x--;
			}
		}
        return (y < row && x >= 0);
    }
};