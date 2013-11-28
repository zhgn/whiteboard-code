// leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
private:
    int gcd(int x, int y) {
        if (x > y) {
            return gcd(y, x);
        }
        if (y % x == 0) {
            return x;
        }
        return gcd(y%x, x);
    }    

    struct Coefficients {
        int A;
        int B;
        int C;
        Coefficients(int _A, int _B, int _C) : A(_A), B(_B), C(_C) {}
        bool operator == (const Coefficients &rhs) const {
            return (A == rhs.A && B == rhs.B && C == rhs.C);
        }
    };

    class CoefficientsHasher {        
    public:
        size_t operator () (const Coefficients &c) const {
            return (c.A << 24) ^ (c.B << 12) ^ c.C;
        }
    };

public:
    int maxPoints(vector<Point> &points) {
        int num = points.size();
        if (num == 1) {
            return 1;
        }
        unordered_map<Coefficients, int, CoefficientsHasher> lines;
        for (int i=0; i<num; i++) {
            for (int j=i+1; j<num; j++) {
                int A = points[i].y - points[j].y;
                int B = points[j].x - points[i].x;
                
                if (A == 0) {
                    B = 1;
                } else if (B == 0) {
                    A = 1;
                } else {
                    if (A < 0) {
                        A = -A;
                        B = -B;
                    }
                    int gcd_of_a_and_b = gcd(abs(A), abs(B));
                    A /= gcd_of_a_and_b;
                    B /= gcd_of_a_and_b;
                }
                
                int C = -(A * points[i].x + B * points[i].y);
                Coefficients c(A, B, C);
                auto it = lines.find(c);
                if (it == lines.end()) {
                    lines.insert(make_pair(c, 0));
                }                 
            }
        }

        int ret = 0;
        for (int i=0; i<num; i++) {
            for (auto line = lines.begin(); line != lines.end(); line++) {
                auto c = line->first;
                if (c.A * points[i].x + c.B * points[i].y + c.C == 0) {
                    (line->second) ++;
                    if (line->second > ret) {
                        ret = line->second;
                    }
                }
            }
        }
        return ret;
    }
};

//[(84,250),(0,0),(0,0),]
int _tmain(int argc, _TCHAR* argv[])
{
    Solution s;
    vector<Point> points;
    points.push_back(Point(0,0));
    points.push_back(Point(1,0));
    points.push_back(Point(1,0));
    points.push_back(Point(84,250));
    
    cout << s.maxPoints(points);
    return 0;
}

