/*
Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

#include "stdafx.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int divisor = 1;
        while (x >= (long long)divisor * 10) {
            divisor *= 10;
        }
        while (x >= 10) {
            if (x / divisor != x % 10) {
                return false;
            }
            x = x % divisor / 10;
            divisor /= 100;
        }
        return true;
    }
};
