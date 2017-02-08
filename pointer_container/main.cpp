#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <vector>

struct Test {
	int uid;
};  // struct Test

typedef std::vector<struct Test*> pTestVec;

int main(void) {
	Test *t1 = new Test();
	t1->uid = 100;

	Test *t2 = new Test();
	t2->uid = 200;

	pTestVec pvec = {t1, t2};

	for (auto p = pvec.begin(); *p != nullptr; ++p) {
		std::cout << (*p)->uid << std::endl;
	}

	delete(t1);
	delete(t2);

	return EXIT_SUCCESS;
}
