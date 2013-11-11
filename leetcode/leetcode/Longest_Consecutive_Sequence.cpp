/* Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

 For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

 Your algorithm should run in O(n) complexity.
 */

#include "stdafx.h"
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    struct ConsInfo {
        int up_to;
        int down_to;
    };

    unordered_map<int, ConsInfo> hash;

    int InsertNumAndRetCurCons(int val) {
        ConsInfo ci;
        unordered_map<int, ConsInfo>::iterator up_it = hash.find(val+1);
        unordered_map<int, ConsInfo>::iterator down_it = hash.find(val-1);
        if (up_it == hash.end()) {
            ci.up_to = val;
        } else {
            ci.up_to = up_it->second.up_to;            
        }
        if (down_it == hash.end()) {
            ci.down_to = val;
        } else {
            ci.down_to = down_it->second.down_to;
        }
        hash.insert(make_pair(val, ci));

        // only need maintain endpoints of interval
        if (up_it != hash.end()) {            
            unordered_map<int, ConsInfo>::iterator up_end = hash.find(up_it->second.up_to);
            up_end->second.down_to = ci.down_to;
        }
        if (down_it != hash.end()) {
            unordered_map<int, ConsInfo>::iterator down_end = hash.find(down_it->second.down_to);
            down_end->second.up_to = ci.up_to;
        }
        return ci.up_to - ci.down_to + 1;
    }

    int longestConsecutive(vector<int> &num) {
        hash.clear();
        int len = num.size();
        int max_cons = 0;

        for (int i=0; i<len; i++) {
            unordered_map<int, ConsInfo>::iterator cur_it = hash.find(num[i]);
            if (cur_it == hash.end()) {
                int cons_len = InsertNumAndRetCurCons(num[i]);
                if (cons_len > max_cons) {
                    max_cons = cons_len;
                }
            } 
        }
        return max_cons;
    }
};
