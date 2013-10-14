#include "stdafx.h"
#include <sstream>

using namespace std;

int sstream_usage()
{
	string s = "224";

	stringstream stream;
    stream << s;
    int ip;
    stream >> ip;

	return 0;
}
