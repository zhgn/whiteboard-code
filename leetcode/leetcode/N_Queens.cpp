/*

The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
 There exist two distinct solutions to the 4-queens puzzle:
 [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
	void solveNQueensHelper(vector<int> &queen, int p, int n, vector<vector<string> > &result)
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
                    vector<string> tmp;
                    for (int j=0;j<n;j++)
                    {
                        string s(n, '.');
                        s[queen[j]] = 'Q';
                        tmp.push_back(s);
                    }
                    result.push_back(tmp);
                }
                else
                {
                    solveNQueensHelper(queen, p+1, n, result);
                }
            }            
        }
    }

public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        vector<int> queen(n,0);

        solveNQueensHelper(queen, 0, n, result);
        return result;
    }        
};