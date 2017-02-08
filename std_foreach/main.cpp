/**
 * @file main.cpp
 * @Synopsis  Using auto in a lambda function.
 *		auto 不能直接使用在 lambda 函数中。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-12-28
 */

#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

typedef std::vector<int32_t> IntegerVec;

void test(int32_t data) {
	std::cout << data*data << std::endl;
}

int main(void) {
	// 而在C++11中，可以定义一个构造函数，接收可以是任意需要类型的{}初始化列表。
	IntegerVec  ivec = {1,2,3,4,5,6}; 

	// 'auto' not allowed in function prototype, auto keyword does not work as a type for function arguments.
	//std::for_each(ivec.begin(), ivec.end(), [](auto it) { std::cout << it << std::endl; } );
	std::for_each(ivec.begin(), ivec.end(), [](decltype(*ivec.begin()) it) { std::cout << it << std::endl; } );

	// 使用range-for循环来遍历vector
	for (int32_t x : ivec) test(x);

	// range-for循环可以遍历任意序列，因此我们可以直接使用初始化列表来简化上面的例子
	for (int32_t x : {1,3,5,7,9,11}) test(x);

	return EXIT_SUCCESS;
}

