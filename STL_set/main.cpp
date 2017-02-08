/**
 * @file main.cpp
 * @Synopsis  Examples for std::set in STL.
 *  包含了经过排序了的数据，这些数据的值(value)必须是唯一的。
 *	注意：输出的集合中的元素是按字母/数字大小顺序排列的，而且每个值都不重复。 
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-04-24
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>

int main(void) {
	std::set<int> S;
	int i = 0;
	std::set<int>::iterator j;
	while (std::cin >> i) {
		S.insert(i);
	}
	for (j = S.begin(); j != S.end(); ++j) {
		std::cout << "Data:" << *j << std::endl;
	}
	return EXIT_SUCCESS;
}
