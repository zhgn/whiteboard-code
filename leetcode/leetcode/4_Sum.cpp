/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
 
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
The solution set must not contain duplicate quadruplets.
 
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = num.size();
        unordered_multimap<int, pair<int, int> > pair_sums;        
        pair_sums.clear();
        sort(num.begin(), num.end());
		vector<vector<int> > result;

        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                int s = num[i] + num[j];			
				pair_sums.insert( make_pair(s, make_pair(i,j)) );
				pair<unordered_multimap<int, pair<int, int> >::iterator, unordered_multimap<int, pair<int, int> >::iterator> range = pair_sums.equal_range( target-s );
				for (unordered_multimap<int, pair<int, int> >::iterator it = range.first; it != range.second; it++ )
				{									
					pair<int, int> *other_two = &(it->second);
					if (other_two->first != i && other_two->second != i && other_two->first != j && other_two->second != j)
					{
						vector<int> fourNum;
						fourNum.clear();
						fourNum.push_back(num[i]);
						fourNum.push_back(num[j]);
						fourNum.push_back(num[other_two->first]);
						fourNum.push_back(num[other_two->second]);
						sort(fourNum.begin(), fourNum.end());
						result.push_back(fourNum);
					}
					it = it++;
				}
            }
        }		
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }    
};
