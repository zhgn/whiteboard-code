#include "stdafx.h"
#include <stack>

using namespace std;

int stack_usage()
{
	stack<int> st;

	st.push(5);
	int x = st.top();
	st.pop();
	if (st.empty()) {
		;
	}

	return 0;
}