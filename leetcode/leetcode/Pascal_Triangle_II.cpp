/*
Given an index k, return the kth row of the Pascal's triangle.

 For example, given k = 3,
 Return [1,3,3,1]. 

Note:
 Could you optimize your algorithm to use only O(k) extra space? 
*/

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(1, 1);        
        for (int i=1; i<=rowIndex; i++) {
            for (int j=i-1; j>0; j--) {
                row[j] = row[j] + row[j-1];
            }
            row.push_back(1);
        }

        return row;
    }
};
