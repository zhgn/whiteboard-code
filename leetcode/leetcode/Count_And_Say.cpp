/*
The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ... 

1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 

Given an integer n, generate the nth sequence. 

Note: The sequence of integers will be represented as a string. 
*/

#include "stdafx.h"
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
		string result = "1";
        for (int i=1; i<n; i++)
		{
			string tmp;
			for (int j=0; j<result.length(); j++)
			{
				int count = 0;
				int k;
				for (k=j+1; k<result.length(), result[k] == result[j]; k++);
				count = k - j;
				stringstream out;
				out << count << result[j];
				tmp += out.str();
				j += count-1;
			}
			result = tmp;
		}
		return result;
    }
};
