#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <vector>

auto main(int32_t, char**) -> int32_t {
	std::vector<int32_t> ivec;
	ivec.push_back(3);
	ivec.push_back(2);
	ivec.push_back(3);
	ivec.push_back(3);
	ivec.push_back(5);
	std::vector<int32_t>::iterator iter;
	int x = 3;
	for (iter = ivec.begin(); iter != ivec.end();) {
		if (*iter == x) {
			iter = ivec.erase(iter);
		} else {
			++iter;
		}
	}

	for (iter = ivec.begin(); iter != ivec.end(); ++iter) {
		printf("value = %d\n", *iter);
	}
	exit(EXIT_SUCCESS);
}
