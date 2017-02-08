#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int op_increase(int i) { return ++i; }
int op_sum(int a, int b) { return a + b; }

int main(int, char**) {
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int>::iterator iter;

	// set some values:
	for (int i = 1; i < 6; ++i) {
		first.push_back(i*10);
	}

	second.resize(first.size());
	// 指出要进行元素变换的第一个迭代器区间 [first1,last1)
	// 指出要进行元素变换的第二个迭代器区间的首个元素的迭代器位置，该区间的元素个数和第一个区间相等
	std::transform(first.begin(), first.end(), second.begin(), op_increase);
	// 对STL的容器中，遍历是一个非常经常采用的动作，为此STL也提供一个算法，for_each:
	std::for_each(second.begin(), second.end(), [&](int x) { std::cout << x << " " << std::endl; });

	std::cout << std::string(30, '-') << std::endl;
	// 指出变换后的结果存放的迭代器区间的首个元素的迭代器位置 
	// 用一元函数对象op作为参数，执行其后返回一个结果值。它可以是一个函数或对象内的类重载operator()
	// 用二元函数对象binary_op作为参数，执行其后返回一个结果值,它可以是一个函数或对象内的类重载operator()
	std::transform(first.begin(), first.end(), second.begin(), first.begin(), op_sum);
	std::for_each(first.begin(), first.end(), [&](int x) { std::cout << x << " " << std::endl; });
	exit(EXIT_SUCCESS);
}

