#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

// 仿函数（functor）
// 针对某个 class 进行 operator() 重载，他就成为一个仿函数
template <typename T> 
class Print {
public:
	void operator()(const T &elem) {
		std::cout << elem << ' ';
	}
};

int main(void) {
	int ia[] = {0, 1, 2, 3, 4, 5};
	std::vector<int> iv(ia, ia + sizeof(ia)/sizeof(ia[0]));
	// 任何 pass by value 操作都会引发 copy 操作，要想形成一个临时对象（无名对象，unnamed objects）
	// 刻意制造临时对象的方法是，在型别名称之后直接加一对小括号，并可以指定初值，例如 int(8), Shape(3, 5)
	// STL 最常将此技巧用于 仿函数（functor）与算法搭配上，如:
	// print<int>()；		// 是一个临时对象，不是一个函数调用操作
	for_each(iv.begin(), iv.end(), Print<int>());
	// 当 for_earch 结束时，这个临时对象也就结束了它的生命。
	return EXIT_SUCCESS;
}
