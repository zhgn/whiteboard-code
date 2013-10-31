/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 
Follow up:
 Did you use extra space?
 A straight forward solution using O(mn) space is probably a bad idea.
 A simple improvement uses O(m + n) space, but still not the best solution.
 Could you devise a constant space solution? 
*/


#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
		int row = matrix.size();
		if (row == 0) {
			return;
		}
		int column = matrix[0].size();
		
		bool is_first_row_zero = false;
		bool is_first_column_zero = false;
		for (int i=0; i<row; i++) {
			if (matrix[i][0] == 0) {
				is_first_column_zero = true;
				break;
			}
		}
        for (int i=0; i<column; i++) {
			if (matrix[0][i] == 0) {
				is_first_row_zero = true;
				break;
			}
		}

		for (int y=1; y<row; y++) {
			for (int x=1; x<column; x++) {
				if (matrix[y][x] == 0) {
					matrix[y][0] = 0;
					matrix[0][x] = 0;
				}
			}
		}

		for (int y=1; y<row; y++) {
			for (int x=1; x<column; x++) {
				if (matrix[y][0] == 0 || matrix[0][x] == 0) {
					matrix[y][x] = 0;					
				}
			}
		}

		if (is_first_row_zero) {
			for (int x=0; x<column; x++) {
				matrix[0][x] = 0;
			}
		}
		if (is_first_column_zero) {
			for (int y=0; y<row; y++) {
				matrix[y][0] = 0;
			}
		}
    }
};
