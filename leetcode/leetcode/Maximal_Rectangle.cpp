/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area. 
*/

#include "stdafx.h"
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int n = matrix.size();
        if (n == 0)
        {
            return 0;
        }
        int m = matrix[0].size();
        vector<vector<int> > up (n, vector<int>(m, 0));
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0)
                    {
                        up[i][j] = 1;
                    }
                    else
                    {
                        up[i][j] = up[i-1][j] + 1;
                    }
                }
            }
        }
        stack<pair<int,int> > st;
        int result = 0;
        st.push(make_pair(-1,-1));
        for (int i=0; i<n; i++)
        {        
            for (int j=0; j<m; j++)
            {
                if (st.top().second <= up[i][j])
                {
                    st.push(make_pair(j, up[i][j]));
                }
                else
                {
                    int left;
                    while (st.top().second > up[i][j])
                    {
                        int s = (j - st.top().first) * st.top().second;
                        if (s > result)
                        {
                            result = s;
                        }
                        left = st.top().first;
                        st.pop();                        
                    }
                    st.push(make_pair(left, up[i][j]));
                }
            }
            while (st.top().first != -1)
            {
                int s = (m - st.top().first) * st.top().second;
                if (s > result)
                {
                    result = s;
                }
                st.pop();
            }
        }
        return result;
    }
};
