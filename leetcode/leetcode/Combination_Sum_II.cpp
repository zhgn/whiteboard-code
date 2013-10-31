/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
Each number in C may only be used once in the combination. 

Note:
 
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
 

For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<vector<int> > > result;
		
		sort(num.begin(), num.end());
		int n = num.size();
		for (int j=0; j<=target; j++)
		{
			vector<vector<int> > tmp;
			result.push_back(tmp);
		}		
		for (int i=0; i<n && num[i]<=target; i++)
		{
			for (int j=target - num[i]; j>=1; j--)
			{
				for (int k=0; k<result[j].size(); k++)
				{
					vector<int> tmp = result[j][k];
					tmp.push_back(num[i]);
					result[ j + num[i] ].push_back(tmp);
				}
			}
			vector<int> tmp;
			tmp.push_back(num[i]);
			result[num[i]].push_back(tmp);
		}

		sort(result[target].begin(),result[target].end());
		result[target].erase(unique(result[target].begin(), result[target].end()), result[target].end());
        return result[target];
    }
};
