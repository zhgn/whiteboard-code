/*
Given a set of distinct integers, S, return all possible subsets. 

Note:
 
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
 

For example,
 If S = [1,2,3], a solution is: 
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	bool next_subset(vector<int> &count) {
		int i = count.size()-1;
		count[i]++;
		while (i>=0 && count[i] > 1) {
			count[i] = 0;
			i--;
			if (i>=0) {
				count[i]++;
			}
		}
		return (i>=0);
	}

public:
    vector<vector<int> > subsets(vector<int> &S) {			
		int num_elements = S.size();
		vector<int> count (num_elements, 0);
		sort(S.begin(), S.end());
		
		vector<vector<int> > ret;
		do {
			vector<int> subset;
			for (int i=0; i<num_elements; i++) {
				if (count[i] > 0) {
					subset.push_back(S[i]);
				}
			}
			ret.push_back(subset);
		}while (next_subset(count));

		return ret;
    }
};
