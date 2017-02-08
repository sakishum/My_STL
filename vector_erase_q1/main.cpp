#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>

int main(int, char**) {
	std::vector<int> ivec;
	ivec.push_back(100);
	ivec.push_back(300);
	ivec.push_back(300);
	ivec.push_back(500);
	std::vector<int>::iterator iter = ivec.begin();
	// 当vector erase 之后，iter 已经指向下一个元素了，不应该再执行 ++iter，否则会跳过下一个元素，跳过第二个 300
	//for (; iter != ivec.end(); ++iter) {
	for (; iter != ivec.end();) {
		if (*iter == 300) {
			iter = ivec.erase(iter);
		} else {
			++iter;
		}
	}
	for (iter = ivec.begin(); iter != ivec.end(); ++iter) {
		std::cout << *iter << ", " << std::endl;
	}
	exit(EXIT_SUCCESS);
}
