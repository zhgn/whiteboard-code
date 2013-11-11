/*
Given a 2D board and a word, find if the word exists in the grid. 

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 
For example,
 Given board = 
[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.
*/

#include "stdafx.h"
#include <vector>

using namespace std;


class Solution {
private:
    vector<vector<bool> > visited;
    int row;
    int column;

    bool exist_helper(vector<vector<char> > &board, string &word, int y, int x, int posi) {
        if (posi == word.length()) {
            return true;
        }
        if (y<0 || y>=row || x<0 || x>=column) {
            return false;
        }
        if (visited[y][x] || board[y][x] != word[posi]) {
            return false;
        }
        visited[y][x] = true;

        static const int dy[4] = {0,1,0,-1};
        static const int dx[4] = {1,0,-1,0};
        for (int i=0; i<4; i++) {
            if (exist_helper(board, word, y+dy[i], x+dx[i], posi+1)) {
                return true;
            }
        }
        visited[y][x] = false;
        return false;
    }

public:
    bool exist(vector<vector<char> > &board, string word) {        
        row = board.size();
        if (row == 0) {
            return false;
        }
        column = board[0].size();
        visited.clear();
        visited.resize(row);
        for (int i=0; i<row; i++) {
            visited[i].resize(column);
        }

        for (int y=0; y<row; y++) {
            for (int x=0; x<column; x++) {
                if (exist_helper(board, word, y, x, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
