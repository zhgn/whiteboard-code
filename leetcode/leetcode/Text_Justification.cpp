/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 
You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 
Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 
For the last line of text, it should be left justified and no extra space is inserted between words.
 
For example,
 words: ["This", "is", "an", "example", "of", "text", "justification."]
 L: 16. 

Return the formatted lines as:
 
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
 

Note: Each word is guaranteed not to exceed L in length. 

click to show corner cases.

Corner Cases: 

A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    string construct_line(vector<string> &words, int start, int end, int space, bool last) {
        string ret = words[start];
        if (start == end - 1) {
            return ret.append(space, ' ');
        }
        int space_num = last ? 1 : space / (end - start - 1) + 1;
        int extra = last ? 0 : space % (end - start - 1);
        for (int i=start+1; i<end; i++) {
            ret.append(space_num + (extra > 0 ? 1 : 0), ' ');
            extra--;
            ret.append(words[i]);
        }
        if (last) {
            ret.append(space, ' ');
        }
        return ret;
    }

public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> text;
        int cur_line_len = 0;
        int start_index = 0;        

        for (int i=0; i<words.size(); i++) {
            int cur_word_len = words[i].length();            
            if (cur_line_len + cur_word_len > L) {
                text.push_back(construct_line(words, start_index, i, L - cur_line_len + 1, false));
                cur_line_len = cur_word_len + 1;
                start_index = i;
            } else {
                cur_line_len += cur_word_len + 1;
            }
        }
        if (words.size() > start_index) {
            text.push_back(construct_line(words, start_index, words.size(), L - cur_line_len + 1, true));
        }
        return text;
    }
};
