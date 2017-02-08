#include <cstdio>
#include <cstdlib>
#include <vector>

typedef std::vector<int> IVEC;

int main(void) {
	IVEC ivec;
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);
	auto iter = ivec.begin();
	auto iterEnd = ivec.end();
	for (; iter != iterEnd; ++iter) {
		printf("%d\n", *iter);
	}

	return EXIT_SUCCESS;
}
