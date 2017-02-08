/**
 * @file main.cpp
 * @Synopsis  splice 是 list 中特有的拼接方法。splice 实现了不需要拷贝的结合，
 *			  这也是选取 list 作为容器的一个因素。即可以在常数时间内从 list
 *			  的一个区域拼接到另一个 list 的一个区域。也就是说 splice 是一个
 *			  常数时间的函数。
 *			  STL 中的 list 就是一个双向链表，可高效地进行插入和删除元素。
 *			  list 不支持随机访问。所以没有 at(pos) 和 operator[]。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-09-15
 */
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <list>
#include "./sk_asio_wrapper_base.h"
#include <boost/container/list.hpp>

using namespace sk_asio_wrapper;

template<typename T>
class print {
public:
	void operator() (const T& iter) const {
		std::cout << iter << " ";
		return;
	}
};  // class print

typedef boost::container::list<int> Blist;
typedef std::list<int> Slist;

auto main(int32_t, char**) -> int32_t {
	Slist list1;
	Slist list2;

	//Blist list1;
	//Blist list2;

	// --------- list 1 -----------
	list1.emplace_back(1);
	list1.emplace_back(2);
	list1.emplace_back(3);
	// --------- list 2 -----------
	list2.emplace_back(4);
	list2.emplace_back(8);
	list2.emplace_back(6);

	do_something_to_all(list1, [&](int &x) { x += 1; });

	// void splice(iterator postion, list &x, iterator first, iterator last);
	list1.splice(list1.end(),
			list2, 
			++list2.begin(),	// 自增，开始位置的下一个
			list2.end());
	// list1: 2 3 4
	// list2: 4 8 6
	//splice_helper(list1, list2, list1.size() + list2.size() - 2);

	std::for_each(list1.begin(), list1.end(), print<int32_t>());	// 仿函数
	std::cout << std::endl;		
	// std::list:					2 3 4 8 6
	std::for_each(list2.begin(), list2.end(), [](int32_t &iter){ std::cout << iter << " ";});	// lambda 
	std::cout << std::endl;		
	// std::list:					4
	exit(EXIT_SUCCESS);
}

