#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <iostream>
#include <algorithm>
#include <boost/bimap.hpp>	/* boost::bimap */

typedef boost::bimap<int32_t, std::string> BM;

int main(void) {
	BM bm;

	bm.left.insert(std::make_pair(1, "111"));
	bm.left.insert(std::make_pair(2, "222"));

	bm.right.insert(std::make_pair("string", 10));
	bm.right.insert(std::make_pair("bimap", 20));
	
	for (auto pos = bm.left.begin(); pos != bm.left.end(); ++pos) {
		std::cout << "first: " << pos->first << ", second: " << pos->second << std::endl;
	}
	return EXIT_SUCCESS;
}
