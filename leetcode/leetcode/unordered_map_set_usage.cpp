#include "stdafx.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

typedef std::unordered_map<std::string,std::string> stringmap;
typedef std::unordered_set<std::string> stringset;

stringmap merge (stringmap a,stringmap b) {
  stringmap temp(a); temp.insert(b.begin(),b.end()); return temp;
}


int unordered_map_usage()
{
    stringmap first;                              // empty
    stringmap second;
    stringmap third;
    stringmap fourth (second);                    // copy
    stringmap fifth (merge(third,fourth));        // move
    stringmap sixth (fifth.begin(),fifth.end());  // range    

    std::unordered_map<std::string,std::string>::const_iterator got = first.find ("input");

    if ( got == first.end() )
        std::cout << "not found";
    else
        std::cout << got->first << " is " << got->second;

    return 0;
}  

int unordered_set_usage()
{
    
    return 0;
}
