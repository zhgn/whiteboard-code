/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include "stdafx.h"
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) {
            return 0;
        }
        switch (s[0]) {
        case 'M':
            return 1000 + romanToInt(s.substr(1));
        case 'C':
            if (s.length() > 1) {
                if (s[1] == 'M') {
                    return 900 + romanToInt(s.substr(2));
                } else if (s[1] == 'D') {
                    return 400 + romanToInt(s.substr(2));
                }
            }
            return 100 + romanToInt(s.substr(1));
        case 'D':
            return 500 + romanToInt(s.substr(1));
        case 'X':
            if (s.length() > 1) {
                if (s[1] == 'C') {
                    return 90 + romanToInt(s.substr(2));
                } else if (s[1] == 'L') {
                    return 40 + romanToInt(s.substr(2));
                }
            }
            return 10 + romanToInt(s.substr(1));
        case 'L':
            return 50 + romanToInt(s.substr(1));
        case 'I':
            if (s.length() > 1) {
                if (s[1] == 'X') {
                    return 9 + romanToInt(s.substr(2));
                } else if (s[1] == 'V') {
                    return 4 + romanToInt(s.substr(2));
                }
            }
            return 1 + romanToInt(s.substr(1));
        case 'V':
            return 5 + romanToInt(s.substr(1));
        }
        return 0;
    }
};
