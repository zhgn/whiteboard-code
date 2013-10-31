#include "stdafx.h"
#include <string>

int string_usage()
{
	std::string str="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)

	std::string str2 = str.substr (12,12);   // "generalities"

	unsigned pos = str.find("live");         // Position of "live" in str

	std::string str3 = str.substr (pos);     // get from "live" to the end

	str3.append(4, ' '); // append 4 spaces

	return 0;
}  




