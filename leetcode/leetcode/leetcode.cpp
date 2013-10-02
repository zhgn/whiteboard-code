// leetcode.cpp : Defines the entry point for the console application.
//

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
		vector<int> prev;
		BFSInfo(int m_dist, int m_prev) 
			: dist(m_dist) 
		{
			prev.push_back(m_prev);
		};
	};
	unordered_map<string, BFSInfo> shortest;
	vector<string> ladder;
	vector<vector<string>> all_results;
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

	void add_result(vector<string> &ladder) {
		vector<string> result;
		for (int index = ladder.size()-1; index>0; index--) {
			result.push_back(ladder[index]);
		}
		all_results.push_back(result);
	}

	void makeResult(vector<string> &cur_ladder, int next_posi) {
		string next_word = ladder[next_posi];
		cur_ladder.push_back(next_word);		

		if (next_posi == 0)
		{		
			add_result(cur_ladder);			
		}
		else
		{
			auto it = shortest.find(next_word);
			for (auto it_prev = it->second.prev.begin(); it_prev != it->second.prev.end(); it_prev++) {
				makeResult(cur_ladder, *it_prev);
			}
		}
		cur_ladder.pop_back();		
	}	

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		all_results.clear();
		shortest.clear();
		ladder.clear();
		ladder.resize(0);
		ladder_head = 0; 		
		ladder.push_back(start);
		BFSInfo tmp_info(0, -1);
		shortest.insert(make_pair(start, tmp_info));
		int dist = 0;
		int sol = dict.size() + 2;
		word_len = start.length();

		while (ladder_head < ladder.size()) {
			string cur = ladder[ ladder_head++ ];
			dist = shortest.find(cur)->second.dist + 1;
			if (dist >= sol) 
				break;
			if (conn(end, cur)) {
				vector<string> tmp_ladder (1, end);	
				makeResult(tmp_ladder, ladder_head-1);						
				sol = dist + 1;
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
							BFSInfo bfs_info(dist, ladder_head - 1);						
							shortest.insert(make_pair(next_word, bfs_info));
							ladder.push_back(next_word);
						} else if (hash_it->second.dist == dist) {
							hash_it->second.prev.push_back(ladder_head - 1);
						}
					}
				}
			}
		}

		return all_results;
    }
};



int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;	
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("b");
	dict.insert("c");
	s.findLadders("a","c",dict);
	return 0;
}

