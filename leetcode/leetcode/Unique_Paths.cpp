/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

 
Above is a 3 x 7 grid. How many possible unique paths are there? 

Note: m and n will be at most 100.
*/

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    // It's the first kind of Stirling
    // Stirling(n,m) means the permutation number of that m marked boxes out of n boxes
    // Stirling(n,m) = S(n-1,m) + S(n-1,m-1)
    int uniquePaths(int m, int n) {
        vector<vector<int>> stirling (n+m, vector<int> (m, 0));
        for (int i=0; i<n+m-1; i++) {
            stirling[i][0] = 1;
            for (int j=1; j<=i && j<m; j++) {
                stirling[i][j] = stirling[i-1][j] + stirling[i-1][j-1];
            }
        }
        return stirling[n+m-2][m-1];
    }
};
