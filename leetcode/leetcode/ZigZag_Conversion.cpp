/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"

 Write the code that will take a string and make this conversion given a number of rows:
 string convert(string text, int nRows);convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
*/

#include "stdafx.h"
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    string convert_when_nrows_is_two(string s) {
        string ret;
        int len = s.length();
        for (int i=0; i<len; i+=2) {
            ret.append(1, s[i]);
        }
        for (int i=1; i<len; i+=2) {
            ret.append(1, s[i]);
        }
        return ret;
    }

public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        if (nRows == 2) {
            return convert_when_nrows_is_two(s);
        }
        int row = nRows - 2;
        int len = s.length();
        int column = len / row + 1;
        vector<vector<char> > board = vector<vector<char> > (nRows, vector<char> (column, '\0'));
        int y=0;
        int x=0;
        int dir = 1;
        int threshold = nRows;
        for (int i=0; i<len; i++) {
            board[y][x] = s[i];
            y += dir;
            if (y == threshold && dir == 1) {
                dir = -1;                
                x ++;
                if (threshold == nRows) {
                    threshold = 0;
                    y -= 2;
                } else {
                    threshold = -1;
                }
            } else if (y == threshold && dir == -1) {
                dir = 1;
                x ++;
                if (threshold == -1) {
                    threshold = nRows - 1;
                    y += 2;
                } else {
                    threshold = nRows;
                }
            }
        }

        string ret;
        for (int i=0; i<nRows; i++) {
            for (int j=0; j<column; j++) {
                if (board[i][j] != '\0') {
                    ret.append(1, board[i][j]);
                }
            }
        }
        return ret;
    }
};
