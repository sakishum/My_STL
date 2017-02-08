#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <functional>

int sum(int arg1, int arg2) {
	std::cout << "arg1 = " << arg1 << std::endl;
	std::cout << "arg2 = " << arg2 << std::endl;

	int sum = arg1 + arg2;
	std::cout << "sum = " << sum << std::endl;

	return sum;
}

int main(void) {
	// ptr_fun 将普通函数（两个参数，如果有多个参数，要改成 boost::bind）适配成
	// bind1st 或 bind2nd 能够使用的 functior, 否则对 bind1st 或 bind2nd 直接绑
	// 定普通函数，编译出错。
	std::bind1st(std::ptr_fun(sum), 1)(2);	// the same as sum(1, 2)
	std::bind2nd(std::ptr_fun(sum), 1)(2);	// the same as sum(2, 1)
	return EXIT_SUCCESS;
}
