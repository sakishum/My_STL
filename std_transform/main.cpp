/**
 * @file main.cpp
 * @Synopsis  无论何时，指定的算法需要指定一个目标区间，
 *			那么必须确保目标区间足够大，或者确保它会随着
 *			算法的运行而增大。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-05-08
 */

#include <cstdlib>
#include <vector>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <functional>
#include <iostream>

int op_increase(int i) { return ++i; }
int op_sum(int i, int j) { return i + j; }

int main(void) {

	std::string s("hello");
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);
	std::cout << s << std::endl;

	std::vector<int> first;
	std::vector<int> second;
	std::vector<int>::iterator iter;

	for (int i = 1; i != 6; ++i) {
		first.push_back(i*10);
	}
	// first: 10 20 30 40 50
	if (second.size() < first.size()) {
		// 如果希望 tranform 覆盖 first ，就需要确保 second 中已有元素数量至少与 first 中的元素一样多。
		std::cout << "resize" << std::endl;
		//second.resize(first.size() - 3);
		second.resize(first.size());
	}
	std::transform(first.begin(), first.end(), second.begin(), op_increase);
	// second: 11 21 31 41 51 
	for (auto & iter : second) {
		std::cout << " " << iter;
	}
	std::cout << std::endl;
	std::cout << "first size: " << first.size() <<  std::endl;		// 5
	std::cout << "second size: " << second.size() <<  std::endl;	// 3
	// if second.size < first.size
	// incorrect checksum for freed object - object was probably modified after being freed.
	std::transform(first.begin(), first.end(), second.begin(), first.begin(), op_sum);
	// first: 21 41 61 81 101
	for (auto & iter : first) {
		std::cout << " " << iter;
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
