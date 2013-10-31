/*

Given a collection of numbers, return all possible permutations. 

For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 

*/

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        int n = num.size();
        vector<int> perm;
        for (int i=0; i<n; i++)
        {
            perm.push_back(i);
        }
        vector<int> tmp;
        vector<vector<int> > result;
        while (true)
        {
            tmp.clear();
            for (int i=0; i<n; i++)
            {
                tmp.push_back(num[perm[i]]);
            }
            result.push_back(tmp);
            
            int posi = n-1;
            for (;posi>0;posi--)
            {
                if (perm[posi] > perm[posi-1])
                {
                    break;
                }
            }
            if (perm[posi] < perm[posi-1])
            {
                break;
            }
            int x = posi;
            while (x<n-1 && perm[posi-1] < perm[x+1])
            {
                x++;
            }
            int swap = perm[posi-1];
            perm[posi-1] = perm[x];
            perm[x] = swap;
            for (int i=posi,j=n-1; i<j; i++,j--)
            {
                swap = perm[i];
                perm[i] = perm[j];
                perm[j] = swap;
            }
        }
        return result;
    }
};
