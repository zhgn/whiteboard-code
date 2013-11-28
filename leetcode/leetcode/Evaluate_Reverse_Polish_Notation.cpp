/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation. 

Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 
Some examples:
 
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
private:
    void evaluate(stack<int> &nums, char op) {
        int rhs = nums.top();
        nums.pop();
        int lhs = nums.top();
        nums.pop();
        int ret;
        switch (op) {
        case '+':
            ret = lhs + rhs;
            break;
        case '-':
            ret = lhs - rhs;
            break;
        case '*':
            ret = lhs * rhs;
            break;
        case '/':
            ret = lhs / rhs;
            break;
        }
        nums.push(ret);
    }

    int convert_to_int(string &s) {
        stringstream stream;
        stream << s;
        int ret;
        stream >> ret;
        return ret;
    }

public:
    int evalRPN(vector<string> &tokens) {
        stack<int> nums;        
        for (int i=0; i<tokens.size(); i++) {
            switch (tokens[i][0]) {
            case '+':
            case '-':
                if (tokens[i].length() != 1) {
                    nums.push(convert_to_int(tokens[i]));
                    break;
                }
            case '*':
            case '/':
                evaluate(nums, tokens[i][0]);
                break;
            default:
                nums.push(convert_to_int(tokens[i]));
            }
        }
        return nums.top();
    }
};
