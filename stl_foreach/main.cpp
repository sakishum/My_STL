#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

template<typename T>
class deletePtr {
public:
	// 用仿函数类，编译器在编译期对函数进行展开，实际上没有函数调用的发生
	void operator()(T *ptr) {
		// delete指针时候，可以再次确认指针类型
		std::cout << *ptr << " " << std::endl;
		delete ptr;
		ptr = nullptr;
	}
};

typedef deletePtr<int32_t> deleteIntPtr;

int main(int, char**) {
	std::deque<int32_t*> xxx;
	xxx.push_back(new int(1));
	xxx.push_back(new int(2));
	xxx.push_back(new int(3));
	xxx.push_back(new int(4));
	xxx.push_back(new int(5));
	// 加强代码自说明能力，减少循环，提高代码可读性
	std::for_each(xxx.begin(), xxx.end(), deleteIntPtr());
	exit(EXIT_SUCCESS);
}

