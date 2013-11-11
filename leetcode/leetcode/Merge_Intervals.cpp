/*
Given a collection of intervals, merge all overlapping intervals.

 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18]. 
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
    static bool interval_cmp(const Interval &a, const Interval &b) {
        if (a.start < b.start)
        {
            return true;
        }
        if (a.start == b.start)
        {
            return (a.end < b.end);
        }
        return false;
    }

public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), &Solution::interval_cmp);
        vector <Interval> result;
        
        int n = intervals.size();
        int i = 0;
        while (i<n)
        {
            Interval tmp(intervals[i].start, intervals[i].end);
            int j = i + 1;
            while (j < n && intervals[j].start <= tmp.end)
            {
                if (intervals[j].end > tmp.end)
                {
                    tmp.end = intervals[j].end;
                }
                j++;
            }   
            i = j;
            result.push_back(tmp);         
        }

        return result;        
    }
};
