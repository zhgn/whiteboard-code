/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row = grid.size();
        if (row == 0) {
            return 0;
        }
        int column = grid[0].size();
        vector<vector<int> > min_path_sum (row, vector<int> (column, 0));

        min_path_sum[0][0] = grid[0][0];
        for (int y=1; y<row; y++) {
            min_path_sum[y][0] = min_path_sum[y-1][0] + grid[y][0];
        }
        for (int x=1; x<column; x++) {
            min_path_sum[0][x] = min_path_sum[0][x-1] + grid[0][x];
        }

        for (int y=1; y<row; y++) {
            for (int x=1; x<column; x++) {
                min_path_sum[y][x] = min(min_path_sum[y-1][x], min_path_sum[y][x-1]) + grid[y][x];
            }
        }
        return min_path_sum[row-1][column-1];
    }
};
