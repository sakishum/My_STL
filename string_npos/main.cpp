#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <string>

// 在 C++ 中常量 npos 是这样定义的：
// static const size_t npos = -1;

auto main(int, char**) -> int32_t {
	std::string str = "Alice Bob Charlie.";
	size_t position = str.find("none");
	//if (position >= 0) {
	if (position != str.npos) {
		std::cout << "Found! position is: " << position<< std::endl;
	} else {
		std::cout << "Not found!" << std::endl;
	}
	exit(EXIT_SUCCESS);
}
