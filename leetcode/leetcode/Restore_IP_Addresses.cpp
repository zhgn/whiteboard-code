/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

 For example:
 Given "25525511135", 

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
*/

#include "stdafx.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
private:
	bool isValidIP(string s) {
        if (s.length() > 1 && s[0] == '0')
            return false;
        stringstream stream;
        stream << s;
        int ip;
        stream >> ip;
        return (ip <= 255);                
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int len = s.length();
        
        for (int i=1; i<len && i<=3; i++)
        {
            for (int j=1; i+j<len && j<=3; j++)
            {
                for (int k=1; i+j+k<len && k<=3; k++)
                {
                    if (len-(i+j+k) > 3)
                    {
                        continue;
                    }
                    if (isValidIP(s.substr(0,i)) && isValidIP(s.substr(i,j)) && 
                        isValidIP(s.substr(i+j,k)) && isValidIP(s.substr(i+j+k, len-(i+j+k))))
                    {
                        string tmp = s.substr(0,i) + "." + s.substr(i,j) + "." +
                            s.substr(i+j,k) + "." + s.substr(i+j+k, len-(i+j+k));
                        result.push_back(tmp);
                    }
                }
            }
        }
        return result;
    }
};
