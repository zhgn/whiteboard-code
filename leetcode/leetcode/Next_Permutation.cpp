/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 
The replacement must be in-place, do not allocate extra memory. 

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 1,2,3 ¡ú 1,3,2
 3,2,1 ¡ú 1,2,3
 1,1,5 ¡ú 1,5,1
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	void swap(vector<int> &num, int p1, int p2)
    {
        int swap = num[p1];
        num[p1] = num[p2];
        num[p2] = swap;
    }

public:
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        int i;
        for (i=n-1; i>0; i--)
        {
            if (num[i] > num[i-1])
            {
                break;
            }
        }
        
        if (i==0)
        {
            sort(num.begin(), num.end());
            return;
        }
        
        int j=i;
        for (; j<n-1; j++)
        {
            if (num[j+1] <= num[i-1])
            {
                break;
            }
        }
        swap(num, j, i-1);
        
        for (int j=i,k=n-1; j<k; j++,k--)
        {
            swap(num, j, k);
        }
    }
};
