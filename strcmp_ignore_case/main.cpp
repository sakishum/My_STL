#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

// 比较两个字符串并忽略大小写
// compare two strings ignoring case
int ciStringCompare(const std::string &str1, const std::string &str2) {
	//return stricmp(str1.c_str(), str2.c_str());
	// http://linux.die.net/man/3/strcasecmp
	return strcasecmp(str1.c_str(), str2.c_str());
}

int main(void) {
	std::string str1("AAAAAbbbbBcccc");
	std::string str2("aaaaabbbbbcccc");
	std::cout << ciStringCompare(str1, str2) << std::endl;
	return EXIT_SUCCESS;
}
