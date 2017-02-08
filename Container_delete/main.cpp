#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <deque>

typedef std::vector<int> IntegerVec;
typedef std::list<int> IntegerList;

bool badValue(int value) {
	bool ret = false;
	if (value < 0) {
		ret = true;
	}
	return ret;
}

int main(void) {
	// vector: deque: string
	IntegerVec ivec = {14234, -345234, 789723, -6827};
	for (auto &item : ivec) {
		std::cout << item << " \t";
	}
	std::cout << std::endl;
	ivec.erase(std::remove(ivec.begin(), ivec.end(), 789723), ivec.end());
	ivec.erase(std::remove_if(ivec.begin(), ivec.end(), badValue), ivec.end());
	for (auto &item : ivec) {
		std::cout << item << " \t";
	}
	std::cout << std::endl;

	// list:
	IntegerList ilist = {14234, -345234, 789723, -6827};
	for (auto &item : ilist) {
		std::cout << item << " \t";
	}
	std::cout << std::endl;
	ilist.remove(789723);
	for (auto &item : ilist) {
		std::cout << item << " \t";
	}
	std::cout << std::endl;

	// map: set: multimap: multiset
	// 直接使用 erase
	return EXIT_SUCCESS;
}
