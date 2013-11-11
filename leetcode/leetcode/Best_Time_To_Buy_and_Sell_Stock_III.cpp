/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/


#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    static const int Maximum = 1 << 29;

    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
        int buy_cost_once = Maximum;
        int buy_cost_twice = Maximum;
        int max_profit_once = 0;
        int max_profit_twice = 0;
        for (int i=0; i<prices.size(); i++) {
            buy_cost_once = min(prices[i], buy_cost_once);
            max_profit_once = max(max_profit_once, prices[i] - buy_cost_once);
            buy_cost_twice = min(buy_cost_twice, prices[i] - max_profit_once);
            max_profit_twice = max(max_profit_twice, prices[i] - buy_cost_twice);
        }
        return max_profit_twice;
    }
};
