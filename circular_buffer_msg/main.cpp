/**
 * @file main.cpp
 * @Synopsis  boost 库里也有形环缓冲区的实现。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-05-16
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <numeric>
#include <boost/typeof/typeof.hpp>		/* BOOST_AUTO */
#include <boost/circular_buffer.hpp>

struct Foo {
	char a;
	int b;
};

typedef boost::circular_buffer<int> ICB;
typedef boost::circular_buffer<struct Foo> SCB;
int main(void) {
	std::cout << " ===================boost::circular_buffer===================" << std::endl;
	std::string str;
	std::cout<<std::numeric_limits<std::string::size_type>::max()/1024<<std::endl;
	std::cout << str.capacity() << std::endl;

	// 创立一个形环缓冲区来放存三个int类型的数据
	//boost::circular_buffer<int> cb(3);
	ICB cb;
	cb.set_capacity(3);

	//插入元素
	cb.push_back(1);
	cb.push_back(2);
	if (!cb.full()) {
		std::cout << "NOT FULL, size: " << cb.size() << std::endl;
		std::cout << "capacity: " << cb.capacity() << std::endl;
	}
	cb.push_back(3);
	if (cb.full()) {
		std::cout << "FULL, size: " << cb.size() << std::endl;
	}
	for (auto &value : cb) {
		std::cout << "value: " << value << "\t";
	}
	std::cout << std::endl;

	// 类型推断, 相当于c++11 中的 auto
	BOOST_TYPEOF(cb[0]) a = cb[0];
	int b = cb[1];
	int c = cb[2];

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	// 注意：circular_buffer 内部存储时循环的，但它的迭代器不是循环的，迭代器仅在begin 与 end 间有效
	std::cout << "begin: " << *cb.begin() << std::endl;
	std::cout << "front: " << cb.front() << std::endl;
	std::cout << "back:  " << cb.back() << std::endl;
	std::cout << "sum: " << std::accumulate(cb.begin(), cb.end(), 0) << std::endl;

	//形环缓冲区在现已满了，继承插入元素将会覆盖掉最面前的元素
	cb.push_back(4);	// 用4覆盖了1
	cb.push_back(5);	// 用5覆盖了2
	cb.push_back(6);	// 用6覆盖了3

	a = cb[0];
	b = cb[1];
	c = cb[2];

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	std::cout << "sum: " << std::accumulate(cb.begin(), cb.end(), 0) << std::endl;

	cb.pop_back();		// 弹出 4
	cb.pop_front();		// 弹出 6

	for (auto &value : cb) {
		std::cout << "value: " << value << "\t";
	}
	std::cout << std::endl;

	int d = cb[0];

	std::cout << "d: " << d << std::endl;

	return EXIT_SUCCESS;
}

