#include <stdio.h>
#include <stdlib.h>
#include <iostream>		// std::cout, std::endl
#include <algorithm>	// std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>		// std::vector

// stl中的heap是类属算法，不是容器，底层基于vector。
// stl中的堆默认是最大堆，要想用最小堆的话，必须要在push_heap,pop_heap,make_heap等
// 每一个函数后面加第三个参数greater<int>()，括号不能省略。
// Initial max heap: 30
// max heap after pop: 20
// max heap after push: 99
// final sorted range: 5 10 15 20 99 

int main(int, char**) {
	int myints[] = {10, 20, 30, 5, 15};
	std::vector<int> ivec(myints, myints + 5);
	std::make_heap(ivec.begin(), ivec.end());
	std::cout << "Initial max heap: " << ivec.front() << std::endl;		// 30

	std::pop_heap(ivec.begin(), ivec.end());
	ivec.pop_back();
	std::cout << "max heap after pop: " << ivec.front() << std::endl;	// 20

	ivec.push_back(99);
	std::push_heap(ivec.begin(), ivec.end());
	std::cout << "max heap after push: " << ivec.front() << std::endl;	// 99

	std::sort_heap(ivec.begin(), ivec.end());

	std::cout << "final sorted range: ";
	std::for_each(ivec.begin(), ivec.end(), [](int elem){
				std::cout << elem << " ";
			});
	std::cout << std::endl;												// 5 10 15 20 99

	exit(EXIT_SUCCESS);
}
