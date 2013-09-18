/* Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region .

 For example,

X X X X
X O O X
X X O X
X O X X


 After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
*/

#include "stdafx.h"
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int num_row;
	int num_column;

	struct Position {
		int y;
		int x;
	};

	stack<Position> st;

	void tryEscape(vector<vector<char>> &board, vector<vector<bool>> &escape) {
		vector<vector<bool>> visited (num_row, vector<bool> (num_column, false));		
		int dy[4] = {-1, 0, 1, 0};
		int dx[4] = {0, 1, 0, -1};

		while (!st.empty()) {
			Position posi = st.top();
			int y = posi.y;
			int x = posi.x;
			st.pop();
		
			visited[y][x] = true;
			escape[y][x] = true;
			
			for (int i=0; i<4; i++) {
				Position new_posi;
				new_posi.y = y+dy[i];
				new_posi.x = x+dx[i];
				if (new_posi.y<0 || new_posi.x<0 || new_posi.y>=num_row || new_posi.x>=num_column) 
					continue;
				if (board[new_posi.y][new_posi.x] == 'X' || visited[new_posi.y][new_posi.x])
					continue;
				
				st.push(new_posi);
			}
		}
	}

    void solve(vector<vector<char>> &board) {
		num_row = board.size();
		if (num_row == 0) {
			return;
		}
		num_column = board[0].size();
		vector<vector<bool>> escape (num_row, vector<bool> (num_column, false));
		
		while (!st.empty()) {
			st.pop();
		}
		for (int y=0; y<num_row; y++) {
			Position posi;
			posi.y = y;
			posi.x = 0;
			if (board[posi.y][posi.x] == 'O') 
				st.push(posi);
			posi.x = num_column-1;
			if (board[posi.y][posi.x] == 'O') 
				st.push(posi);			
		}
		for (int x=0; x<num_column; x++) {
			Position posi;
			posi.x = x;
			posi.y = 0;
			if (board[posi.y][posi.x] == 'O') 
				st.push(posi);
			posi.y = num_row-1;
			if (board[posi.y][posi.x] == 'O') 
				st.push(posi);			
		}
		tryEscape(board, escape);

		for (int y=0; y<num_row; y++) {
			for (int x=0; x<num_column; x++) {
				if ((!escape[y][x]) && board[y][x] == 'O')
					board[y][x] = 'X';
			}
		}
    }
};
