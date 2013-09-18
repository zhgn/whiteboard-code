/* Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the dictionary

 For example,

 Given:
 start = "hit"
 end = "cog"
 dict = ["hot","dot","dog","lot","log"]


 Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]


 Note:

All words have the same length.
All words contain only lowercase alphabetic characters.

*/

#include "stdafx.h"
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
	typedef struct _BFSInfo {
		int dist;
		int prev;
	}BFSInfo;
	unordered_map<string, BFSInfo> shortest;
	vector<string> ladder;
	int ladder_head;
	int ladder_tail;

	bool conn(string a, string b)
	{
		int len = a.length();
		int count = 0;
		for (int i=0; i<len; i++) {
			if (a[i] != b[i]) {
				count++;
				if (count > 1) {
					return false;
				}
			}
		}
		return (count == 1);
	}

	void makeResult(int posi) {		
		if (posi > 0) {
			makeResult(ladder[pos


    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<string>> all_results;
		shortest.clear();
		ladder.clear();
		ladder_head = 0; 
		ladder_tail = 1;
		ladder.push_back(start);
		shortest.insert(make_pair(start, 0));
		int dist = 0;
		int sol = dict.size() + 2;

		while (ladder_head < ladder_tail) {
			string cur = ladder[ ladder_head++ ];
			dist = shortest.find(cur)->second.dist + 1;
			if (dist >= sol) 
				break;
			if (conn(end, cur)) {
				vector<string> result = makeResult(posi);
				all_results.
				sol = dist + 1;
			}
			for (unordered_set<string>::const_iterator c_it = dict.cbegin(); c_it != dict.cend(); c_it++) {
				if (conn(*c_it, cur)) {
					auto hash_it = shortest.find(*c_it);
					if (hash_it == shortest.end()) {
						BFSInfo bfs_info;
						bfs_info.dist = dist;
						bfs_info.prev = ladder_head - 1; 
						shortest.insert(make_pair(*c_it, bfs_info));
					}
				}
			}
		}
    }
};
