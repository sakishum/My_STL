#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>

typedef std::vector<int> IVEC;

int main(void) {
	IVEC ivec;
	ivec.reserve(1000);	// vector 的reserve增加了vector的capacity，但是它的size没有改变
	// resize改变了vector的capacity同时也增加了它的size
	for (int i = 0; i != 1000; ++i) {
		ivec.push_back(i);
	}

	std::cout << "size    : " << ivec.size() << std::endl;
	std::cout << "capacity: " << ivec.capacity() << std::endl;

	for (auto &iter : ivec) {
		std::cout << iter << ",";
	}
	return EXIT_SUCCESS;
}
