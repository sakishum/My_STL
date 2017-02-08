#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

// The behaverior of for_each template function is equivalent to:
template<typename InputIterator, typename Function>
Function  for_each_dx(InputIterator beg, InputIterator end, Function f) {
	while (beg != end) {
		f(*beg++);
	}
	return f;	// or, since C++11: return move(f)
}

// Global function
// procedure base 不传入参
void printVec(int elem) {
	std::cout << elem << std::endl;
}

// 若要传参数给 global function，就不能只传 global function name 而已， 必须透过 ptr_fun() 这个
// function adapter 将 globale function 转成 function object, 然后再用 bin2nd() 将参数 bind 成
// 一个 function object。
// 详见 ../ptr_fun_dx
void printVecDx(int elem, const char *prefix) {
	std::cout << prefix << elem << std::endl;
}

void printVecEx(const char *prefix, int elem) {
	std::cout << prefix << elem << std::endl;
}

// 临时对象
// Object oriented / function object
// 仿函数(functor), 就是使用起来像函数一样的东西。
// 如果针对某个 class 进行 operator() 重载，他就成为一个仿函数。
// 不传入参数
struct PrintVec {
	void operator()(int elem) {
		std::cout << elem << std::endl;
	}
};

// 传入参数
// 若使用 function object，也可以将参数传给 PrintVecDx()，透过 constructor 的技巧接收参数。
struct PrintVecDx {
	const char *_prefix;
	PrintVecDx(const char *prefix) : _prefix(prefix) {}
	void operator()(int elem) {
		std::cout << _prefix << elem << std::endl;
	}
};

// function object 有很多种写法，但只要是 function 都可以跟 for_each() 合作。
class Foo {};

int main(void) {
	int ia[] = {1, 2, 3};
	std::vector<int> ivec(ia, ia + sizeof(ia)/sizeof(int));
	for_each_dx(ivec.begin(), ivec.end(), printVec);
	// ptr_fun : global function -> function object
	for_each_dx(ivec.begin(), ivec.end(), std::bind2nd(std::ptr_fun(printVecDx), "Element:"));	// the same as printVecDx(elem, "Element:")
	for_each_dx(ivec.begin(), ivec.end(), std::bind1st(std::ptr_fun(printVecEx), "Element:"));	// the same as printVecDx("Element:", elem)
	for_each_dx(ivec.begin(), ivec.end(), PrintVec());	// 仿函数(funtor)
	for_each_dx(ivec.begin(), ivec.end(), PrintVecDx("Element:"));
	// 通过以上代码可知，for_each() 只能配合global function 和 function object。
	return EXIT_SUCCESS;
}
