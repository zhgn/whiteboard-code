/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
 
For example, given:
 S: "barfoothefoobarman"
 L: ["foo", "bar"] 

You should return the indices: [0,9].
 (order does not matter). 
*/

#include "stdafx.h"
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<string, int> dict;
    vector<int> word_count;

    void insert_into_dict(const vector<string> &L) {
        dict.clear();
        word_count.clear();
        int id = 0;
        for (int i=0; i<L.size(); i++) {
            auto it = dict.find(L[i]);
            if (it == dict.end()) {
                dict.insert(make_pair(L[i], id));
                word_count.push_back(1);
                id++;
            } else {
                word_count[it->second] ++;
            }
        }
    }

public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if (L.size() == 0) {
            return ret;
        }
        int word_len = L[0].length();
        int tot_len = word_len * L.size();
        insert_into_dict(L);
        
        vector<int> words_id (S.length(), -1);
        for (int i=0; i <= (int)S.length() - word_len; i++) {
            auto it = dict.find(S.substr(i, word_len));
            if (it != dict.end()) {
                words_id[i] = it->second;
            }
        }
        
        for (int i=0; i <= (int)S.length() - tot_len; i++) {
            bool is_valid = true;
            vector<int> cur_count (L.size(), 0);
            for (int j=0; j<tot_len; j+=word_len) {
                int id = words_id[i+j];
                if (id >= 0) {
                    cur_count[id]++;
                    if (cur_count[id] > word_count[id]) {
                        is_valid = false;
                        break;
                    }
                } else {
                    is_valid = false;
                    break;
                }
            }

            if (is_valid) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
