/**
 * @file main.cpp
 * @Synopsis  deque容器为一个给定类型的元素进行线性处理，像向量一样，
 *		它能够快速地随机访问任一个元素，并且能够高效地插入和删除容器
 *		的尾部元素。但它又与vector不同，deque支持高效插入和删除容器
 *		的头部元素，因此也叫做双端队列。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-11-05
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <algorithm>
#include <deque>

auto main(int, char**) -> int32_t {
	std::deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	std::cout << "Origin data: " << std::endl;
	std::for_each(d.begin(), d.end(), [](std::deque<int>::value_type &value) {
				std::cout << value << ", ";
			});
	std::cout << std::endl;
	d.push_front(5);
	d.push_front(3);
	d.push_front(1);
	std::cout << "After push_front(5, 3, 1): " << std::endl;
	std::for_each(d.begin(), d.end(), [](std::deque<int>::value_type &value) {
				std::cout << value << ", ";
			});
	std::cout << std::endl;
	// 支持 []
	std::cout << "d[2] = " << d[2] << std::endl;
	d.pop_front();
	d.pop_front();
	std::cout << "After pop_front() two items: " << std::endl;
	std::for_each(d.begin(), d.end(), [](std::deque<int>::value_type &value) {
				std::cout << value << ", ";
			});
	std::cout << std::endl;
	exit(EXIT_SUCCESS);
}

