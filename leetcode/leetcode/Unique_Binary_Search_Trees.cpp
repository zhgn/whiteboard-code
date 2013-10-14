/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

 For example,
 Given n = 3, there are a total of 5 unique BST's. 
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

#include "stdafx.h"
#include <algorithm>

class Solution {
private:
	int calatan(int n) {
		long long ret = 1;
		for (int i=1; i<=n; i++) {
			ret *= n+i;
		}
		for (int i=1; i<=n; i++) {
			ret /= i;
		}
		return ret/(n+1);
	}

public:
    int numTrees(int n) {
        return calatan(n);        
    }
};