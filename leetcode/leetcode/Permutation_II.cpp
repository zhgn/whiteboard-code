/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 
For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1]. 
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        int n = num.size();
        vector<int> tmp;
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        while (true)
        {
            tmp.clear();
            for (int i=0; i<n; i++)
            {
                tmp.push_back(num[i]);
            }
            result.push_back(tmp);
            
            int posi = n-1;
            for (;posi>0;posi--)
            {
                if (num[posi] > num[posi-1])
                {
                    break;
                }
            }
            if (num[posi] <= num[posi-1])
            {
                break;
            }
            int x = posi;
            while (x<n-1 && num[posi-1] < num[x+1])
            {
                x++;
            }
            int swap = num[posi-1];
            num[posi-1] = num[x];
            num[x] = swap;
            for (int i=posi,j=n-1; i<j; i++,j--)
            {
                swap = num[i];
                num[i] = num[j];
                num[j] = swap;
            }
        }
        return result;    
    }
};
