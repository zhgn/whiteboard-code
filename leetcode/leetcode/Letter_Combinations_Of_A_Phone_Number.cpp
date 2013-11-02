/*
Given a digit string, return all possible letter combinations that the number could represent.
 
A mapping of digit to letters (just like on the telephone buttons) is given below.
 
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
private:
	string digit_to_c[10];
    void init_digit_to_c() {
    	digit_to_c[0] = " ";
		digit_to_c[1] = "";
		digit_to_c[2] = "abc";
		digit_to_c[3] = "def";
		digit_to_c[4] = "ghi";
		digit_to_c[5] = "jkl";
		digit_to_c[6] = "mno";
		digit_to_c[7] = "pqrs";
		digit_to_c[8] = "tuv";
		digit_to_c[9] = "wxyz";   
    }

public:
    vector<string> letterCombinations(string digits) {
	    init_digit_to_c();

		vector<string> result;
		if (digits.length() == 0)
		{
			result.push_back("");
			return result;
		}
		vector<string> tmp = letterCombinations(digits.substr(1));
		{
			for (int j=0; j<tmp.size(); j++)
			{
				int x = digits[0] - '0';
				for (int i=0; i<digit_to_c[x].length(); i++)
				{					
                    string s = string(1, digit_to_c[x][i]).append(tmp[j]);
					result.push_back(s);
				}
			}
		}
		return result;
    }
};
