#include "stdafx.h"
#include <vector>
#include <algorithm>

int vector_usage()
{
	unsigned int i;

	// constructors used in the same order as described above:
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	// erase dup
	std::sort(fifth.begin(), fifth.end());
	fifth.erase(std::unique(fifth.begin(), fifth.end()), fifth.end());

	return 0;
}  

