/**
 * @file main.cpp
 * @Synopsis  boost 库里也有形环缓冲区的实现。
 *		術語 循環緩衝區circular buffer 通常指的是內存中的一塊用於保存輸
 *		入數據的區域。當緩衝區被填入時，新的數據從緩衝區的開始被寫入，
 *		並覆蓋掉舊的數據。
 *		写服务器的代码时，为了减少内存的分配，我们很多时候需要一个池子，
 *		讲需要分配的资源先new出来，放在池子里面。这个池子的总长度（容量）
 *		应该是大部分时候是固定。
 *		设计思路:
 *		使用一个内存数据区作为数据存放区，可以在开始位置和结束位置进行插
 *		入和删除操作，开始和，结束位置的指针可以变化，通过模除保证队列可
 *		以循环；长度可以扩展；如果队列已经满了，提供插入的时候提供是否覆
 *		盖的选择。
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
#include "./lordrings.h"

/**
 * @Synopsis  print 
 *		输出容器内部的所有元素
 * @tparam T	容器类型
 * @Param cb	容器对象
 */
template<typename T>
void print(T &cb) {
	std::cout << "The data: ";
	// 用于仿真C++新标准的typeof和auto关键字
	for (BOOST_AUTO(pos, cb.begin()); pos != cb.end(); ++pos) {
		std::cout << *pos << ", ";
	}
	std::cout << std::endl;
}

int main(void) {
	std::cout << " ===================boost::circular_buffer===================" << std::endl;
	std::string str;
	std::cout<<std::numeric_limits<std::string::size_type>::max()/1024<<std::endl;
	std::cout << str.capacity() << std::endl;

	// 创立一个形环缓冲区来放存三个int类型的数据
	boost::circular_buffer<int> cb(3);

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
	print(cb);

	// 类型推断, 相当于c++11 中的 auto
	BOOST_TYPEOF(cb[0]) a = cb[0];
	int b = cb[1];
	int c = cb[2];
	int *arr = cb.linearize();		// 获取线性数组
	printf("arfter linearize cb[0] = %d\n", arr[0]);
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
	print(cb);

	a = cb[0];
	b = cb[1];
	c = cb[2];

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	std::cout << "sum: " << std::accumulate(cb.begin(), cb.end(), 0) << std::endl;

	cb.pop_back();		// 弹出 4
	cb.pop_front();		// 弹出 6
	print(cb);

	int d = cb[0];

	std::cout << "d: " << d << std::endl;

	// ===================lordrings=================== 
	std::cout << " ===================lordrings===================" << std::endl;
	zenlib::lordrings<int>* rl = new zenlib::lordrings<int>(3);

	rl->push_back(1);
	rl->push_back(2);
	rl->push_back(3);

	a = (*rl)[0];
	b = (*rl)[1];
	c = (*rl)[2];

	std::cout << "a: " << a << std::endl;	// 1
	std::cout << "b: " << b << std::endl;	// 2
	std::cout << "c: " << c << std::endl;	// 3

	std::cout << rl->capacity() << std::endl;

	rl->push_back(4, true);
	rl->push_back(5);
	rl->push_back(6);

	a = (*rl)[0];
	b = (*rl)[1];
	c = (*rl)[2];

	std::cout << "a: " << a << std::endl;	// 2
	std::cout << "b: " << b << std::endl;	// 3
	std::cout << "c: " << c << std::endl;	// 4

	return EXIT_SUCCESS;
}

