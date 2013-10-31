/*
You are given an n x n 2D matrix representing an image.
 
Rotate the image by 90 degrees (clockwise).
 
Follow up:
 Could you do this in-place?
*/

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
private:
	void rotate(vector<vector<int> > &matrix, int n, int y, int x) {
		int tmp = matrix[y][x];
		matrix[y][x] = matrix[n-x-1][y];
		matrix[n-x-1][y] = matrix[n-y-1][n-x-1];
		matrix[n-y-1][n-x-1] = matrix[x][n-y-1];
		matrix[x][n-y-1] = tmp;
	}

public:
    void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		int half = n / 2;
		for (int y=0; y<half; y++) {
			for (int x=0; x<half; x++) {
				rotate(matrix, n, y, x);
			}
		}
		if (n%2 == 1) {
			for (int y=0; y<half; y++) {
				rotate(matrix, n, y, half);
			}
		}
    }
};
