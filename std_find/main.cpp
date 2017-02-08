/**
 * @file main.cpp
 * @Synopsis  Example of std::find for boost::shared_ptr.
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-12-16
 */

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>    // std::find
#include <vector>
#include <string>
#include <boost/smart_ptr.hpp>

typedef boost::shared_ptr<std::string> StringPtr;
typedef std::vector<StringPtr> StringPtrVec;

int main(void) {
	StringPtrVec svec;
	StringPtr ptr1(new std::string("aaa"));
	StringPtr ptr2(new std::string("bbb"));
	StringPtr ptr3(new std::string("ccc"));

	StringPtr ptr4 = ptr2;
	
	svec.push_back(ptr1);
	svec.push_back(ptr2);
	svec.push_back(ptr3);

	auto iter = std::find(svec.begin(), svec.end(), ptr4); 
	if (iter != svec.end()) {
		std::cout << "The target is " << *(*iter) << std::endl;
	}
	
	return EXIT_SUCCESS;
}
