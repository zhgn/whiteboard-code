/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2 
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> find_index(vector<int> &numbers, int a, int b) {
        vector<int> ret;
        for (int i=0; i<numbers.size(); i++) {
            if (numbers[i] == a) {
                ret.push_back(i+1);
            } else if (numbers[i] == b) {
                ret.push_back(i+1);
            }
        }
        return ret;
    }

public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> sorted_numbers (numbers);
        sort(sorted_numbers.begin(), sorted_numbers.end());
        for (int i=0,j=sorted_numbers.size()-1; i<j; ) {
            int sum = sorted_numbers[i] + sorted_numbers[j];
            if (sum == target) {                
                return find_index(numbers, sorted_numbers[i], sorted_numbers[j]);
            }
            if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return vector<int>();
    }
};
