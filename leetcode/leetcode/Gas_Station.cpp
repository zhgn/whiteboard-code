/*
Gas Station

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 
Note:
 The solution is guaranteed to be unique. 
 */

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    int prev(int x, int n) {        
        return (x == 0) ? n-1 : x-1;
    }

    int next(int x, int n) {        
        return ( x == n-1) ? 0 : x+1;
    }

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {        
        int start = 0;
        int station_num = gas.size();
        int gas_diff = 0;
        int end = 0;
        do {            
            if (gas_diff < 0) {
                start = prev(start, station_num);
                gas_diff += gas[start] - cost[start];
            } else {
                gas_diff += gas[end] - cost[end];
                end = next(end, station_num);
            }            
        } while (start != end);

        return (gas_diff >= 0) ? start : -1;
    }
};
