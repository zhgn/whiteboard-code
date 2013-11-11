/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.
 
Note:
 
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 

For example,
 If S = [1,2,2], a solution is: 
[
  [2],
  [1],
  [1,2,2],
  [2,2],
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
    struct S_Element_Info {
        int val;
        int count;
        S_Element_Info(int val) : val(val), count(1) {};
    };    

    bool next_subset(vector<int> &count, vector<S_Element_Info> &elements_info) {
        int i = count.size()-1;
        count[i]++;
        while (i>=0 && count[i] > elements_info[i].count) {
            count[i] = 0;
            i--;
            if (i>=0) {
                count[i]++;
            }
        }
        return (i>=0);
    }

public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<S_Element_Info> elements_info;
        int i=0; 
        while (i<S.size()) {
            S_Element_Info tmp(S[i]);
            while (i<S.size()-1 && S[i+1] == S[i]) {
                tmp.count++;
                i++;
            }
            elements_info.push_back(tmp);
            i++;
        }
        int num_elements = elements_info.size();
        vector<int> count (num_elements, 0);
        
        vector<vector<int> > ret;
        do {
            vector<int> subset;
            for (int i=0; i<num_elements; i++) {
                for (int j=0; j<count[i]; j++) {
                    subset.push_back(elements_info[i].val);
                }
            }
            ret.push_back(subset);
        }while (next_subset(count, elements_info));

        return ret;
    }
};

