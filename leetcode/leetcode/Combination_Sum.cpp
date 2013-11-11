/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
The same repeated number may be chosen from C unlimited number of times. 

Note:
 
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ... , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
 

For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<vector<int> > > result;
        
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        int n = candidates.size();
        for (int j=0; j<=target; j++)
        {
            vector<vector<int> > tmp;
            result.push_back(tmp);
        }        
        for (int i=0; i<n && candidates[i]<=target; i++)
        {
            vector<int> tmp;
            tmp.push_back(candidates[i]);
            result[candidates[i]].push_back(tmp);
            for (int j=1; j+candidates[i] <= target; j++)
            {
                for (int k=0; k<result[j].size(); k++)
                {
                    vector<int> tmp = result[j][k];
                    tmp.push_back(candidates[i]);
                    result[ j + candidates[i] ].push_back(tmp);
                }
            }
        }

        return result[target];
    }
};
