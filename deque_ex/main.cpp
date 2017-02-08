#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

// 结果发现原先保持的指针元素值对vector容器前后发生了变化，而对deque容器前后没有发生变化。
// 在建立vector容器时，一般来说伴随着:
// 建立空间->填充数据->重建更大空间->复制原空间数据->删除原空间->添加新数据，如此反复，保证vector始终是一块独立的连续内存空间
// 在建立deque容器时，一般便随着:
// 建立空间->建立数据->建立新空间->填充新数据，如此反复，没有原空间数据的复制和删除过程，是由多个连续的内存空间组成的
auto main(int, char **) -> int32_t {
	std::vector<int> v(2);
	v[0] = 10;
	int *p = &v[0];
	std::cout << "vector 第一个元素迭代器指针 *p = " << *p << std::endl;	// 10
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	std::cout << "vector 容量变化后原 vector 第一个元素迭代器指针 *p = " << *p << std::endl;	// 0

	std::deque<int> d(2);
	d[0] = 10;
	int *q = &d[0];
	std::cout << "deque 第一个元素迭代器指针 *q = " << *q << std::endl;		// 10
	d.push_back(20);
	std::cout << "deque 容量变化后原 deque 第一个元素迭代器指针 *q = " << *q << std::endl;		// 10

	exit(EXIT_SUCCESS);
}
