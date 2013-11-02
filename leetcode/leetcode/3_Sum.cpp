/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
 
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
 
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:	
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());        
        vector<vector<int>> result;
		result.clear();
        if (num.size() < 3) {
            return result;
        }

		vector<int> tmp;
		for (int i=0; i<num.size()-2; i++)
		{            
            if (i > 0 && num[i] == num[i-1]) {
                continue;
            }
			for (int j=i+1, k=num.size()-1; j<k;)
			{
				int s = num[i] + num[j] + num[k];
				if (s==0)
				{						
					tmp.clear();
					tmp.push_back(num[i]);
					tmp.push_back(num[j]);
					tmp.push_back(num[k]);
					result.push_back(tmp);		
					do {
                        j++;     
                    } while (j<k && num[j] == num[j-1]);
                    do {
                        k--;    
                    } while (j<k && num[k] == num[k+1]);
				}
				else if (s<0)
				{
		            do {
                        j++;     
                    } while (j<k && num[j] == num[j-1]);
				}
				else
				{					
                    do {
                        k--;    
                    } while (j<k && num[k] == num[k+1]);
				}
			}
		}		
		return result;
    }
};
