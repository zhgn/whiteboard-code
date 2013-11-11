/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

 For example,
 Given n = 3, 
You should return the following matrix: [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret = vector<vector<int> > (n, vector<int>(n, 0));
        
        int dy[4] = {0, 1, 0, -1};
        int dx[4] = {1, 0, -1, 0};
        int count = 0;
        int total = n * n;
        for (int circle=0; circle<(n+1)/2; circle++) {
            int y = circle;
            int x = circle;
            for (int dir=0; dir<4; dir++) {
                int len = n - circle*2 - 1;
                for (int i=0; i<len; i++) {
                    ret[y][x] = ++count;
                    y+=dy[dir];
                    x+=dx[dir];
                }
                if (len == 0 && count == total - 1) {
                    ret[y][x] = ++count;
                }
                if (count == total) {
                    break;
                }
            }
        }

        return ret;        
    }
};
