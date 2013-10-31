/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 
For example,
 If n = 4 and k = 2, a solution is: 
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        if (k==1)
        {
            vector<int> tmp;
            for (int i=1; i<=n; i++)
            {
                tmp.push_back(i);
                result.push_back(tmp);
                tmp.pop_back();
            }
            return result;
        }
        for (int i=k;i<=n;i++)
        {
            vector<vector<int> > re = combine(i-1,k-1);
            for (int j=0;j<re.size();j++)
            {
                re[j].push_back(i);
                result.push_back(re[j]);
            }
        }
        return result;        
    }
};