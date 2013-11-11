/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 
For example,
 Given the following matrix: 
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
 
You should return [1,2,3,6,9,8,7,4,5]. 
*/

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        int row = matrix.size();
        if (row == 0) {
            return ret;
        }
        int column = matrix[0].size();

        int dy[4] = {0, 1, 0, -1};
        int dx[4] = {1, 0, -1, 0};
        int count = 0;
        int total = row * column;
        for (int circle=0; circle<(row+1)/2 && circle<(column+1)/2; circle++) {
            int y = circle;
            int x = circle;
            for (int dir=0; dir<4; dir++) {
                int len = abs(dy[dir]) * (row - circle * 2 - 1) + abs(dx[dir]) * (column - circle * 2 - 1);
                for (int i=0; i<len; i++) {
                    ret.push_back(matrix[y][x]);
                    y+=dy[dir];
                    x+=dx[dir];
                    count++;
                }
                if (len == 0 && count == total - 1) {
                    ret.push_back(matrix[y][x]);                    
                    count++;
                }
                if (count == total) {
                    break;
                }
            }
        }

        return ret;
    }
};