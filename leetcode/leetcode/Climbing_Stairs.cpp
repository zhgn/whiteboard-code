/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include "stdafx.h"

class Solution {
public:
    int climbStairs(int n) {
        int step_two = 0;
        int step_one = 1;
        for (int i=1; i<=n; i++) {
            int tmp = step_two + step_one;
            step_two = step_one;
            step_one = tmp;
        }
        return step_one;
    }
};
