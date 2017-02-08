/**
 * @file main.cpp
 * @Synopsis  Example for list@STL find method in CPP. 
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-03-19
 */

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <list>

int main(void) {
	std::list<int> l1;
	l1.push_back(4);
	l1.push_back(2);
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(6);
	l1.push_back(3);
	l1.push_back(3);
	l1.push_back(5);
	std::list<int>::iterator iter = find(l1.begin(), l1.end(), 7);
	if (l1.end() != iter) {
		printf("The data is %d\n", *iter);
	} else {
		printf("Not found\n");
	}
	/// 排序
	l1.sort();
	/// 删除重复项
	l1.erase( unique( l1.begin(), l1.end() ), l1.end());	//Remove duplicate list values 
	for (std::list<int>::iterator iter = l1.begin(); iter != l1.end(); ++iter) {
		printf("The element is %d\n", *iter);
	}
	return EXIT_SUCCESS;
}


