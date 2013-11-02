/*
Divide two integers without using multiplication, division and mod operator. 
*/

#include "stdafx.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        int positive = 1;        
        long long ll_dividend = dividend;
        long long ll_divisor = divisor;
        if (ll_dividend < 0)
        {
            positive = 0 - positive;
            ll_dividend = 0LL - ll_dividend;
        }
        if (ll_divisor < 0)
        {
            ll_divisor = 0LL - ll_divisor;
            positive = 0 - positive;
        }
        if (ll_dividend < ll_divisor)
        {
            return 0;
        }
        long long x = ll_divisor;
        long long d = ll_dividend;      

        int y = 1;
        int result = 0;
        while (d >= (x << 1))
        {
            x <<= 1;
            y <<= 1;
        }
        while (d >= ll_divisor)
        {
            if (d >= x)
            {
                d -= x;
                result += y;
            }                
            y >>= 1;
            x >>= 1;    
        }
        return (positive>0 ? result : -result);
    }
};