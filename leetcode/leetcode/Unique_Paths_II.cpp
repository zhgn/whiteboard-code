/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
 

There is one obstacle in the middle of a 3x3 grid as illustrated below.
 [
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
 
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

#include "stdafx.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size();
        if (row == 0) {
            return 0;
        }
        int column = obstacleGrid[0].size();
        if (column == 0 || obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        vector<vector<int> > paths_num = vector<vector<int> > (row+1, vector<int>(column+1, 0));
                
        paths_num[1][1] = 1;
        for (int i=1; i<=row; i++) {
            for (int j=(i==1 ? 2 : 1); j<=column; j++) {
                if (obstacleGrid[i-1][j-1] == 0) {
                    paths_num[i][j] = paths_num[i-1][j] + paths_num[i][j-1];
                }
            }
        }
        return paths_num[row][column];
    }
};

