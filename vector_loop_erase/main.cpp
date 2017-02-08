#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <vector>
#include <boost/smart_ptr.hpp>

struct Test;

typedef boost::shared_ptr<Test> TestPtr;

struct Test {
	Test(int32_t exp, int64_t uid) : m_exp(exp), m_uid(uid) {
	}
	int32_t m_exp;
	int64_t m_uid;
};

typedef std::vector<TestPtr> TestPtrVec;

int main(void) {
	TestPtrVec vec;
	TestPtr ptr1(new Test(100, 123));
	TestPtr ptr2(new Test(200, 124));
	TestPtr ptr3(new Test(300, 125));
	TestPtr ptr4(new Test(400, 126));
	TestPtr ptr5(new Test(300, 127));
	TestPtr ptr6(new Test(600, 128));

	vec.push_back(ptr1);
	vec.push_back(ptr2);
	vec.push_back(ptr3);
	vec.push_back(ptr4);
	vec.push_back(ptr5);
	vec.push_back(ptr6);

	for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
		std::cout << (*iter)->m_exp << "\t";
	}
	std::cout << std::endl;

	for (auto iter = vec.begin(); iter != vec.end();) {
		if ((*iter)->m_exp == 300) {
			iter = vec.erase(iter);
		} else {
			++iter;
		}
	}

	for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
		std::cout << (*iter)->m_exp << "\t";
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
