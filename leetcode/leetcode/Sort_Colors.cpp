/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 
Note:
 You are not suppose to use the library's sort function for this problem. 

 
Follow up:
 A rather straight forward solution is a two-pass algorithm using counting sort.
 First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 
Could you come up with an one-pass algorithm using only constant space?
*/

#include "stdafx.h"

class Solution {
private:
	void swap(int A[], int pos1, int pos2) {
		int tmp = A[pos1];
		A[pos1] = A[pos2];
		A[pos2] = tmp;
	}

public:
    void sortColors(int A[], int n) {		
		for (int i=0, zeros=0, ones=0; i<n; i++) {
			if (A[i] == 0) {
				swap(A, zeros, i);
				if (A[i] == 1) {
					swap(A, ones + zeros, i);
				}
				zeros++;					
			} else if (A[i] == 1) {
				swap(A, ones + zeros, i);
				ones++;
			}
		}
    }
};
