/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution. 
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int possible[9][9][10];
    int possible_count[9][9];
    bool stop;

    void init_possible(vector<vector<char> > &board) {        
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') {
                    for (int k=1; k<=9; k++) {
                        possible[i][j][k] = 1;
                    }
                    possible_count[i][j] = 9;
                }                
            }
        }
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] != '.') {
                    mark_others(board, i, j, board[i][j] - '0', false);
                }
            }
        }        
    }

    bool mark(int y, int x, int val, bool undo)
    {                
        possible[y][x][val] += undo ? 1 : -1;
        if (possible[y][x][val] == 0 && (!undo)) {    
            possible_count[y][x]--;
        }
        if (possible[y][x][val] == 1 && undo) {
            possible_count[y][x]++;
        }
        return (possible_count[y][x] != 0 || undo);
    }

    bool mark_others(vector<vector<char> > &board, int y, int x, int val, bool undo) {        
        bool is_valid = true;
        for (int i=0; i<9; i++) {        
            if (!mark(y, i, val, undo) && (board[y][i] == '.')) {
                is_valid = false;                
            }            
            if (!mark(i, x, val, undo) && (board[i][x] == '.')) {
                is_valid = false;                
            }
        }
        int start_y = y/3*3;
        int start_x = x/3*3;
        for (int i=start_y; i<start_y+3; i++) {
            for (int j=start_x; j<start_x+3; j++) {                
                if (!mark(i, j, val, undo) && (board[i][j] == '.')) {
                    is_valid = false;
                }
            }
        }
        return is_valid;
    }

    bool find_next(vector<vector<char> > &board, int &y, int &x) {
        int min_possible_count = 10;
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.' && min_possible_count > possible_count[i][j]) {
                    min_possible_count = possible_count[i][j];
                    y=i;
                    x=j;
                }
            }
        }
        return (min_possible_count < 10);
    }

    void solve_sudoku_helper(vector<vector<char> > &board, int y, int x) { 
        if (stop) {
            return;
        }
        for (int val=1; val<=9; val++) {
            if (possible[y][x][val] > 0 && (!stop)) {
                board[y][x] = '0' + val;
                if (mark_others(board, y, x, val, false)) {                    
                    int new_y;
                    int new_x;
                    if (find_next(board, new_y, new_x)) {                    
                        solve_sudoku_helper(board, new_y, new_x);                    
                    } else {
                        stop = true;
                    }
                }
                if (!stop) {
                    board[y][x] = '.';
                    mark_others(board, y, x, val, true);
                }
            }
        }        
    }

public:
    void solveSudoku(vector<vector<char> > &board) {
        init_possible(board);
        int y;
        int x;
        stop = false;
        if (!(find_next(board, y, x))) {
            return;
        }
        solve_sudoku_helper(board, y, x);
    }
};
