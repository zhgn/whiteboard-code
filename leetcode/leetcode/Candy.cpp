/* There are N children standing in a line. Each child is assigned a rating value. 

You are giving candies to these children subjected to the following requirements:
 Each child must have at least one candy.
 Children with a higher rating get more candies than their neighbors.
 
What is the minimum candies you must give? 

*/

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct ChildInfo {
        int rating;
        int posi;
        ChildInfo(int p_rating, int p_posi) :
            rating(p_rating), 
            posi(p_posi)    
            {};
    };

    static bool child_cmp(const ChildInfo &a, const ChildInfo &b) {
        return a.rating < b.rating;
    }

    int getCandyNum(int posi, const vector<int> &candy_assign, const vector<int> &ratings, int rating) {
        if (posi < 0 || posi >= candy_assign.size()) {
            return 0;
        }
        return (rating > ratings[posi]) ? candy_assign[posi] : 0;        
    }

    int candy(vector<int> &ratings) {
        int children_num = ratings.size();
        vector<ChildInfo> children_info;
        for (int i = 0; i < children_num; i++) {
            ChildInfo tmp(ratings[i], i);
            children_info.push_back(tmp);
        }
        sort(children_info.begin(), children_info.end(), child_cmp);
        
        int total_candy = 0;
        vector<int> candy_assign (children_num, 0);
        for (int i = 0; i < children_num; i++) {            
            int left_candy = getCandyNum(children_info[i].posi-1, candy_assign, ratings, children_info[i].rating);
            int right_candy = getCandyNum(children_info[i].posi+1, candy_assign, ratings, children_info[i].rating);            
            candy_assign[ children_info[i].posi ] = (left_candy > right_candy ? left_candy : right_candy) + 1;
            total_candy += candy_assign[ children_info[i].posi ];            
        }
        return total_candy;
    }
};
