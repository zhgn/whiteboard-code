/* Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
 1.Only one letter can be changed at a time
 2.Each intermediate word must exist in the dictionary
 
For example, 

Given:
 start = "hit"
 end = "cog"
 dict = ["hot","dot","dog","lot","log"]
 

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 return its length 5. 

Note:
 
•Return 0 if there is no such transformation sequence.
 •All words have the same length.
 •All words contain only lowercase alphabetic characters.

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
	struct BFSInfo {
		int dist;	
		BFSInfo (int m_dist) : dist(m_dist) {};
	};
	unordered_map<string, BFSInfo> shortest;
	vector<string> ladder;	
	int ladder_head;
	int ladder_tail;
	int word_len;

	bool conn(string a, string b)
	{		
		int count = 0;
		for (int i=0; i<word_len; i++) {
			if (a[i] != b[i]) {
				count++;
				if (count > 1) {
					return false;
				}
			}
		}
		return (count == 1);
	}

    int ladderLength(string start, string end, unordered_set<string> &dict) {
		shortest.clear();
		ladder.clear();
		ladder.resize(0);
		ladder_head = 0; 		
		ladder.push_back(start);
		BFSInfo tmp_info(1);
		shortest.insert(make_pair(start, tmp_info));
		int dist = 0;
		word_len = start.length();

		while (ladder_head < ladder.size()) {
			string cur = ladder[ ladder_head++ ];
			dist = (shortest.find(cur))->second.dist + 1;			
			if (conn(end, cur)) {
				return dist;	
			}
			for (int i=0; i<word_len; i++) {
				for (char ch='a'; ch<='z'; ch++) {
					if (cur[i] == ch) {
						continue;
					}
					string next_word = cur;
					next_word[i] = ch;
					auto c_it = dict.find(next_word);
					if (c_it != dict.end()) {
						auto hash_it = shortest.find(next_word);
						if (hash_it == shortest.end()) {
							BFSInfo bfs_info(dist);
							shortest.insert(make_pair(next_word, bfs_info));
							ladder.push_back(next_word);
						} 
					}
				}
			}
		}

		return 0;
    }
};
