/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/


#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {    		
		bool used[9];
		
		for (int y=0; y<9; y++) {
			memset(used, 0, sizeof(used));
			for (int i=0; i<9; i++) {
				if (board[y][i] != '.') {
					int val = board[y][i] - '0';
					if (used[val]) {
						return false;
					}
					used[val] = true;
				}
			}
		}
		
		for (int x=0; x<9; x++) {
			memset(used, 0, sizeof(used));
			for (int i=0; i<9; i++) {
				if (board[i][x] != '.') {
					int val = board[i][x] - '0';
					if (used[val]) {
						return false;
					}
					used[val] = true;
				}
			}
		}

		for (int start_y = 0; start_y < 9; start_y += 3) {
			for (int start_x = 0; start_x < 9; start_x += 3) {
				memset(used, 0, sizeof(used));
				for (int i=start_y; i<start_y+3; i++) {
					for (int j=start_x; j<start_x+3; j++) {	
						if (board[i][j] != '.') {
							int val = board[i][j] - '0';
							if (used[val]) {
								return false;
							}
							used[val] = true;
						}
					}
				}
			}
		}
		return true;	
    }
};
