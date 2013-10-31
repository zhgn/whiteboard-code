/*
Given an array of strings, return all groups of strings that are anagrams. 

Note: All inputs will be in lower-case.
*/

#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		vector <bool> save (strs.size(), false);	
		vector <string> result;
		
		unordered_map<string, int> dict;
		for (int i=0; i<strs.size(); i++)
		{			
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			auto it = dict.find(tmp);
			if (it == dict.end())
			{
				dict[tmp] = i;
			}
			else
			{
				save[(it->second)] = true;
				save[i] = true;
			}
		}
		for (int i=0; i<strs.size(); i++)
		{
			if (save[i])
			{
				result.push_back(strs[i]);
			}
		}
		return result;
    }    	
};