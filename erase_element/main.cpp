#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

typedef std::vector<int> IVEC;

int main(void) {
	int a[] = {1, 2, 3, 4};
	IVEC ivec(a, a+sizeof(a)/sizeof(a[0]));
	std::cout << "ivec.size(): " << ivec.size() << std::endl;
	for (auto &iter : ivec) {
		std::cout << "elemen: " << iter << std::endl;
	}
	std::cout << std::string(30, '_') << std::endl;
	auto beg = ivec.begin();
#if 0
	auto end = ivec.end();
	while (beg != end) {
		if ((*beg) > 2) {
			beg = ivec.erase(beg);
			end = ivec.end();
		} else {
			++beg;
		}
	}
#else 
	for (; beg != ivec.end();) {
		if ((*beg) > 2) {
			beg = ivec.erase(beg);
		} else {
			++beg;
		}
	}
#endif
	for (auto &iter : ivec) {
		std::cout << "elemen: " << iter << std::endl;
	}
	return EXIT_SUCCESS;
}
