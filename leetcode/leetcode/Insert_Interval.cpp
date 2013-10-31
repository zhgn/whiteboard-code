/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9]. 

Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
*/

#include "stdafx.h"
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		int n = intervals.size();
		int s,e;
		for (s=0; s<n; s++)
		{
			if (intervals[s].end >= newInterval.start)
				break;
		}		
		if (s == n)
		{
			intervals.push_back(newInterval);
			return intervals;
		}
		if (intervals[s].start < newInterval.start)
		{
			newInterval.start = intervals[s].start;
		}
		for (e=s; e<n; e++)
		{
			if (intervals[e].start > newInterval.end)
			{
				break;
			}
		}
		if (e>0 && intervals[e-1].end > newInterval.end && intervals[e-1].start <= newInterval.end)
		{
			newInterval.end = intervals[e-1].end;
		}
		vector<Interval> result;
		for (int i=0;i<s;i++)
		{
			result.push_back(intervals[i]);
		}
		result.push_back(newInterval);
		for (int i=s;i<n;i++)
		{
			if (intervals[i].start <= newInterval.end)
			{
				continue;
			}
			result.push_back(intervals[i]);
		}
		return result;
	}	
};
