/**
 * @file main.cpp
 * @Synopsis  std::string 的 COW（copy-on-write）技术，常用于对象的复制中。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-09-15
 */
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <string>

void test(const std::string &str) {
	//char *tmp = (char*)str.c_str();
	char *tmp = const_cast<char*>(str.c_str());
	tmp[1] = 'a';
}

auto main(int32_t, char**) -> int32_t {
	std::string str1("test");
	std::string str2;
	str2 = str1;
	std::string str3(str1);
	str1[1] = 't';
	std::cout << "Before: " << str1 << std::endl;
	test(str1);
	std::cout << "After : " << str1 << std::endl;
	exit(EXIT_SUCCESS);
}
