#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <boost/smart_ptr.hpp>

class Test {
public:
	Test(void) {
		std::cout << "Test\'s constructor called." << std::endl;
	}
	~Test(void) {
		std::cout << "Test\'s destructor called." << std::endl;
	}
};

typedef boost::shared_ptr<Test> TestPtr;
typedef std::map<int, TestPtr> TestPtrMap;

int main(void) {
	TestPtrMap tmap;
	{
		TestPtr ptr = boost::make_shared<Test>();
		tmap.insert(std::make_pair(1, ptr));
	}
	std::cout << "Before map swap empty container." << std::endl;
	// 使用 swap 技巧清除 map 内所有数据，并使 map 容量为 0
	TestPtrMap().swap(tmap);
	std::cout << "After map swap empty container." << std::endl;
	std::cin.get();
	return EXIT_SUCCESS;
}

