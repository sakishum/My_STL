/**
 * @file main.cpp
 * @Synopsis  Example for fun_ptr, mem_fun, mem_fun_ref.
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-06-25
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <boost/smart_ptr.hpp>
#include <boost/bind.hpp>

class Test {
public:
	Test(int data = 0) : _data(data) { }
	void print(void) {
		std::cout << "I am class Test::_data " << _data << std::endl;
	}
	void add(int val) {
		_data += val;
	}
private:
	int _data;
};

typedef boost::shared_ptr<Test> TestPtr;

int main(void) {
	// mem_fun_ref
	std::cout << "mem_fun_ref:" << std::endl;
	Test test1(3);
	Test test2(4);
	std::vector<Test> tvec;
	tvec.push_back(test1);
	tvec.push_back(test2);

	// for_each() 只能配合 global function 和 function object.
	// 透过 mem_fun_ref() 这个 function adapter 将 member function 转成 function object.
	for_each(tvec.begin(), tvec.end(), std::mem_fun_ref(&Test::print));
	for_each(tvec.begin(), tvec.end(), std::bind2nd(std::mem_fun_ref(&Test::add), 3));
	std::cout << std::string(30, '-') << std::endl;
	for_each(tvec.begin(), tvec.end(), std::mem_fun_ref(&Test::print));

	// mem_fun
	std::cout << std::string(30, '=') << std::endl;
	std::cout << "mem_fun:" << std::endl;
	std::vector<Test*> pvec;
	Test *p1 = new Test(5);
	Test *p2 = new Test(6);
	pvec.push_back(p1);
	pvec.push_back(p2);

	// mem_fun 与 mem_fun_ref 的作用跟用法一样， 唯一不同的就是: 当容器中存放的是 对象实体 的时候
	// 用 mem_fun_ref, 当容器中存放的是 对象的指针 的时候用 mem_fun .
	for_each(pvec.begin(), pvec.end(), std::mem_fun(&Test::print));
	std::cout << std::string(30, '-') << std::endl;
	for_each(pvec.begin(), pvec.end(), std::bind2nd(std::mem_fun(&Test::add), 4));
	for_each(pvec.begin(), pvec.end(), std::mem_fun(&Test::print));
	pvec.clear();
	delete p1;
	delete p2;

	// boost::bind
	// 当容器中存放的是 对象的智能指针的时候，使用 boost::bind 
	std::cout << std::string(30, '=') << std::endl;
	std::cout << "Boost::bind:" << std::endl;
	std::vector<TestPtr> ptvec;
	TestPtr ptr1 = boost::make_shared<Test>(7);
	TestPtr ptr2 = boost::make_shared<Test>(8);
	ptvec.push_back(ptr1);
	ptvec.push_back(ptr2);
	for_each(ptvec.begin(), ptvec.end(), boost::bind(&Test::print, _1));
	std::cout << std::string(30, '-') << std::endl;
	for_each(ptvec.begin(), ptvec.end(), boost::bind(&Test::add, _1, 5));
	for_each(ptvec.begin(), ptvec.end(), boost::bind(&Test::print, _1));
	return EXIT_SUCCESS;
}
