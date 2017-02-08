#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

#include <boost/smart_ptr.hpp>
class Test;
typedef boost::shared_ptr<Test> TestPtr;
class Test {
public:
	Test(void) : m_roleid(0), m_exp(0) {
		std::cout << "Constructor." << std::endl;
	}
	Test(uint64_t uid, uint64_t exp) : m_roleid(uid), m_exp(exp) {
	
	}
	~Test(void) {
		std::cout << "Disstructor." << getuid() << std::endl;;
	}

	uint64_t getuid(void) const {
		return m_roleid;
	}

	uint64_t getexp(void) const {
		return m_exp;
	}

	bool operator()(TestPtr x, TestPtr y) const {
		return x->m_exp > y->m_exp;
	}

private:
	uint64_t m_roleid;
	uint64_t m_exp;
};  // struct Test

typedef std::list<TestPtr> TestLiist;
typedef std::vector<TestPtr> TestVec;

int main(void) {
	TestVec vec;

	TestPtr t1(new Test(123, 200));
	TestPtr t2(new Test(124, 500));
	TestPtr t3(new Test(125, 300));
	TestPtr t4(new Test(126, 600));
	TestPtr t5(new Test(127, 100));
	TestPtr t6(new Test(128, 400));

	vec.push_back(t2);
	vec.push_back(t3);
	vec.push_back(t6);
	vec.push_back(t5);
	vec.push_back(t1);
	vec.push_back(t4);

	for (auto it=vec.begin(); it != vec.end(); ++it)
		std::cout << ' ' << (*it)->getuid() << ", " << (*it)->getexp();
	std::cout << std::endl;

	std::sort(vec.begin(), vec.end());

	for (auto it=vec.begin(); it != vec.end(); ++it)
		std::cout << ' ' << (*it)->getuid() << ", " << (*it)->getexp();
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
