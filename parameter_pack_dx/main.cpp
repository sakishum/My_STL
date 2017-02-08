/**
 * @file main.cpp
 * @Synopsis   变长函数模板，兼容 printf， 仍然提供 printf 式字符串，所以 myprint
 *		等同于 printf，可以接受该字符串及变长参数。而 myprint 的功能也大于 printf，
 *		因为它可以接受sstd::string 这样的非内置类型。
 *
 *		相比于变长函数，变长函数模板不会丢弃参数的类型信息。因此重载的 std::cout 
 *		的操作符 << 总是可以将具有类型的变量正确地打印出来。这就是 myprint 比 print
 *		功能强大的主要原因，也是变长模板函数远强于变长函数的地方。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-12-27
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

void myprint(const char *s) {
	while (*s) {
		if (*s == '%' && *++s != '%') {
			throw std::runtime_error("invalid format string:missing arguments.");
		}
		std::cout << *s++;
	}
}

template <typename T, typename... Args>
void myprint(const char *s, T value, Args... args) {
	while (*s) {
		if (*s == '%' && *++s != '%') {
			std::cout << value;
			return myprint(++s, args...);
		}
		std::cout << *s++;
	}
	throw std::runtime_error("Extra arguments provided to myprint.");
}

int main(void) {
	myprint("Hello %s%\n", std::string("world"));
	return EXIT_SUCCESS;
}
