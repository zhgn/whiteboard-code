/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 
You have the following 3 operations permitted on a word: 

a) Insert a character
 b) Delete a character
 c) Replace a character
*/

#include "stdafx.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len_1 = word1.length();
        int len_2 = word2.length();
        vector<vector<int> > dis (len_1 + 1, vector<int> (len_2 + 1, 0)); 
        for (int i=0; i<=len_1; i++) {
            dis[i][0] = i;
        }
        for (int i=0; i<=len_2; i++) {
            dis[0][i] = i;
        }

        for (int i=1; i<=len_1; i++) {
            for (int j=1; j<=len_2; j++) {
                dis[i][j] = min(min(dis[i-1][j] + 1, dis[i][j-1] + 1), dis[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1));    
            }
        }
        return dis[len_1][len_2];
    }
};
