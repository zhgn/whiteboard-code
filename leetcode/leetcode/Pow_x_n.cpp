/*
Implement pow(x, n). 
*/

#include "stdafx.h"

class Solution {
public:
    double pow(double x, int n) {
        bool positive = (n >= 0);
        
        double ret = 1;
        double y = x;
        while (n)
        {            
            if (n%2)
            {
                ret *= y;
            }
            n /= 2;
            y *= y;
        }
        if (!positive)
        {
            ret = 1/ret;
        }        
        return ret;
    }
};
