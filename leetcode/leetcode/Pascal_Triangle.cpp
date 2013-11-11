/*
Given numRows, generate the first numRows of Pascal's triangle.

 For example, given numRows = 5,
 Return 
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > pascal_tri;
        if (numRows <= 0)
            return pascal_tri;

        vector<int> first_row (1, 1);
        pascal_tri.push_back(first_row);
        for (int i=1; i<numRows; i++) {
            vector<int> cur_row (1, 1);            
            for (int j=1; j<i; j++) {
                cur_row.push_back(pascal_tri[i-1][j-1] + pascal_tri[i-1][j]);
            }
            cur_row.push_back(1);
            pascal_tri.push_back(cur_row);
        }
        return pascal_tri;
    }
};
