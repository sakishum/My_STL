/**
 * @file main.cpp
 * @Synopsis  测试了 map 的 emplace 和 vector 的 emplace_back，用 map 的 insert 方法插入元素时有两次内存移动，
 *		而用 emplace 时只有一次内存移动；用 vector 的 push_back 插入元素时有两次移动内存，而用 emplace_back
 *		时没有内存移动，是直接构造的。
 *
 *		可以看到，emplace/emplace_back 的性能比之前的 insert 和 push_back 的性能要提高很多，我们应该尽量用
 *		emplace/emplace_back 来代替原来的插入元素的接口以提高性能。需要注意的是，我们还不能完全用
 *		emplace_back 来取代 push_back 等老接口，因为在某些场景下并不能直接使用 emplace 来进行就地构造，比如，
 *		当结构体中没有提供相应的构造函数时就不能用 emplace 了，这时就只能用 push_back。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-08-25
 */

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>

struct Complicated {
	int32_t year;
	double country;
	std::string name;
	Complicated(int32_t a, double b, const std::string &c) :year(a), country(b), name(c) {
		std::cout << "is constructed" << std::endl;
	}

	Complicated(const Complicated &other) :year(other.year), country(other.country), name(std::move(other.name)) {
		std::cout << "is move" << std::endl;
	}
};  // struct Complicated

auto main(int, char**) -> int32_t {
	std::map<int32_t, Complicated> m;
	int32_t anInt = 4;
	double aDouble = 5.0f;
	std::string aString = "C++";

	std::deque<int32_t> id = {10, 20, 30};
	auto it = id.emplace(id.begin()+1, 100);
	id.emplace(it, 200);
	id.emplace(id.end(), 300);
	id.emplace_back(900);

	std::cout << "std::deque<int32_t> contains: ";
	for (auto &x: id) {
		std::cout << ' ' << x;
	}
	std::cout << std::endl;
	std::deque<Complicated> d;
	std::cout << "--push_back--" << std::endl;
	d.push_back(Complicated(anInt, aDouble, aString));
	std::cout << "--emplace_back--" << std::endl;
	d.emplace_back(anInt, aDouble, aString);
	exit(EXIT_SUCCESS);
}
