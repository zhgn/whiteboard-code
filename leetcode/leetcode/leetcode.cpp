// leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
				else {
					for (int k=1; k<=9; k++) {
						possible[i][j][k] = (board[i][j] - '0' == k) ? 1 : 0;
					}
					possible_count[i][j] = 1;
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
			if (!mark(y, i, val, undo) && board[y][i] == '.') {
				is_valid = false;			
			}
			if (!mark(i, x, val, undo) && board[i][x] == '.') {
				is_valid = false;			
			}
		}
		int start_y = y/3*3;
		int start_x = x/3*3;
		for (int i=start_y; i<start_y+3; i++) {
			for (int j=start_x; j<start_x+3; j++) {				
				if (!mark(i, j, val, undo) && board[i][j] == '.') {
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


int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;	
	vector<vector<char> > input;
	vector<char> x;
	string str = "..9748...";
	for (int i=0; i<9; i++) {
		x.push_back(str[i]);
	}
	input.push_back(x);
	str = "7........";
	x.clear();
	for (int i=0; i<9; i++) {
		x.push_back(str[i]);
	}
	input.push_back(x);
	str = ".2.1.9...";
	x.clear();
	for (int i=0; i<9; i++) {
		x.push_back(str[i]);
	}
	input.push_back(x);
	str = "..7...24.";
	x.clear();
	for (int i=0; i<9; i++) {
		x.push_back(str[i]);
	}
	input.push_back(x);
	str = ".64.1.59.";
	x.clear();
	for (int i=0; i<9; i++) {
		x.push_back(str[i]);
	}
	input.push_back(x);
	str = ".98...3..";
	x.clear();
	for (int i=0; i<9; i++) {
		x.push_back(str[i]);
	}
	input.push_back(x);
	str = "...8.3.2.";
	x.clear();
	for (int i=0; i<9; i++) {
		x.push_back(str[i]);
	}
	input.push_back(x);
	str = "........6";
	x.clear();
	for (int i=0; i<9; i++) {
		x.push_back(str[i]);
	}
	input.push_back(x);
	str = "...2759..";
	x.clear();
	for (int i=0; i<9; i++) {
		x.push_back(str[i]);
	}
	input.push_back(x);
	
	s.solveSudoku(input);
	return 0;
}

