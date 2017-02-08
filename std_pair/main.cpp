/**
 * @file main.cpp
 * @Synopsis  std::pair可以将两个值看做一个单元来处理。C++标准库中多处使用了std::pair，
 *		其中map和multimap就是使用std::pair来管理键/值(key/value)对的。任何函数如果返回
 *		两个值，都可以使用std::pair。下面的代码简单介绍如何std::pair。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-12-22
 */

#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

int main(void) {
	typedef std::pair<int32_t, std::string> Student;
	// 初始化 pair 的第一种方式，通过构造函数初始化
	Student stu_first(2011, "hahaya");

	// 初始化 pair 的第二种方式，通过初始化成员变量
	Student stu_second;
	stu_second.first = 2014;
	stu_second.second = "Tomas";

	// 初始化 pair 的第三种方式，通过辅助函数 std::make_pair 来初始化
	Student stu_third = std::make_pair(2013, "http://google.com");

	// std::pair 对象的输出
	std::cout << "number: " << stu_first.first << "\tname: " << stu_first.second << std::endl;
	std::cout << "number: " << stu_second.first << "\tname: " << stu_second.second << std::endl;
	std::cout << "number: " << stu_third.first << "\tname: " << stu_third.second << std::endl;
	return EXIT_SUCCESS;
}
