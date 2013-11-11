/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    void totalNQueensHelper(vector<int> &queen, int p, int n, int &result)
    {
        for (int i=0; i<n; i++)
        {
            bool ok = true;
            for (int j=0; j<p; j++)
            {
                if (queen[j] == i || abs(queen[j] - i) == abs(j-p))
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                queen[p] = i;
                if (p == n-1)
                {
                    result++;
                }
                else
                {
                    totalNQueensHelper(queen, p+1, n, result);
                }
            }            
        }
    }

public:
    int totalNQueens(int n) {
        int result = 0;
        vector<int> queen(n,0);

        totalNQueensHelper(queen, 0, n, result);
        return result;
    }        
};
