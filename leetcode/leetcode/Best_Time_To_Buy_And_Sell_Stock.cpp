/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/


#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if (prices.size() == 0)
			return 0;
        int min_price = prices[0];
		int max_profit = 0;
		for (auto it = prices.begin(); it != prices.end(); it++) {
			min_price = min(min_price, *it);
			max_profit = max(max_profit, *it - min_price);
		}
		return max_profit;
    }
};
