/*
Validate if a given string is numeric.

 Some examples:
 "0" => true
 " 0.1 " => true
 "abc" => false
 "1 a" => false
 "2e10" => true
 

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

#include "stdafx.h"
#include <cstring>

class Solution {
private:
    // Status 
    // 0: Before plus/minus sign
    // 1: After plus/minus sign, before integer part
    // 2: Integer part
    // 3: After dot, decimal part    
    // 4: After 'e', before exponent part plus/minus sign
    // 5: After exponent part plus/minus sign    
    // 6: Exponent part
    // 7: Finish
    // 8: Special, no integer but a dot
    int trans[9][6];

    int char_kind(char c) {
        if (c == ' ') {
            return 0;
        }
        if (c == '.') {
            return 1;
        }
        if (c == 'e') {
            return 2;
        }
        if (c == '+' || c == '-') {
            return 3;
        }
        if (c >= '0' && c <= '9') {
            return 4;
        }        
        return 5;
    }

    void init_trans() {    
        for (int i=0; i<9; i++) {
            for (int j=0; j<6; j++) {
                trans[i][j] = -1;
            }
        }
        // ' '
        trans[0][0] = 0;         
        trans[2][0] = 7;
        trans[3][0] = 7;        
        trans[6][0] = 7;        
        trans[7][0] = 7;
        // '.'
        trans[0][1] = 8; trans[1][1] = 8;
        trans[2][1] = 3; 
        // 'e'
        trans[2][2] = 4; trans[3][2] = 4;
        // '+', '-'
        trans[0][3] = 1;
        trans[4][3] = 5;
        // num
        trans[0][4] = 2; trans[1][4] = 2; trans[2][4] = 2;
        trans[3][4] = 3; 
        trans[4][4] = 6; trans[5][4] = 6; trans[6][4] = 6;        
        trans[8][4] = 3;
    }

public:
    bool isNumber(const char *s) {
        init_trans();
        int status = 0;
        for (int i=0; s[i] != '\0'; i++) {
            status = trans[status][ char_kind(s[i]) ];
            if (status == -1) {
                return false;
            }
        }
        status = trans[status][ char_kind(' ') ];
        return (status == 7);
    }
};
