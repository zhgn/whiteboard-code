/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"
 

click to show corner cases.

Corner Cases:
 
Did you consider the case where path = "/../"?
 In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 In this case, you should ignore redundant slashes and return "/home/foo".
*/

#include "stdafx.h"
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string simple_path = "/";
        stack<int> name_pos;
        name_pos.push(1);
        
        int last_slash = 0;
        for (int i=1; i<path.length(); i++) {
            if (path[i] == '/') {
                string cur = path.substr(last_slash+1, i-last_slash);
                if (cur != "/" && cur != "./") {
                    if (cur == "../") {
                        if (name_pos.top() > 1) {    
                            name_pos.pop();
                            simple_path = simple_path.substr(0, name_pos.top());                        
                        }
                    } else {
                        simple_path += cur;
                        name_pos.push(name_pos.top() + cur.length());
                    }
                }
                last_slash = i;
            }
        }
        if (path.length() > 0 && path[path.length() - 1] != '/') {
            string cur = path.substr(last_slash+1);
            if (cur != ".") {
                if (cur == "..") {
                    if (name_pos.top() > 1) {    
                        name_pos.pop();
                        simple_path = simple_path.substr(0, name_pos.top());
                    }
                } else {
                    simple_path += cur;    
                }
            }            
        }        
        if (simple_path.length() > 1 && simple_path[simple_path.length() - 1] == '/') {
            simple_path = simple_path.substr(0, simple_path.length() - 1);
        }
        return simple_path;
    }
};
