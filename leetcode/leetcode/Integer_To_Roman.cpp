/*
Given an integer, convert it to a roman numeral. 

Input is guaranteed to be within the range from 1 to 3999.
*/

#include "stdafx.h"
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        if (num == 0)
        {
            return "";
        }
        if (num <= 3)
        {
            string s;
            s.assign(num, 'I');
            return s;
        }
        if (num < 5)
        {
            return intToRoman(5 - num) + "V";
        }
        if (num < 9)
        {
            return "V" + intToRoman(num - 5);
        }
        if (num < 10)
        {
            return "IX";
        }
        if (num < 40)
        {
            return "X" + intToRoman(num - 10);
        }
        if (num < 50)
        {
            return "XL" + intToRoman(num - 40);
        }
        if (num < 90)
        {
            return "L" + intToRoman(num - 50);
        }
        if (num < 100)
        {
            return "XC" + intToRoman(num - 90);
        }
        if (num < 400)
        {
            return "C" + intToRoman(num - 100);
        }
        if (num < 500)
        {
            return "CD" + intToRoman(num - 400); 
        }
        if (num < 900)
        {
            return "D" + intToRoman(num - 500);
        }
        if (num < 1000)
        {
            return "CM" + intToRoman(num - 900);
        }
        if (num >= 1000)
        {
            return "M" + intToRoman(num - 1000);
        }
        return "";
    }
};
