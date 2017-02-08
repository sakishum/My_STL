/**
 * @file main.cpp
 * @Synopsis  变参模板(Variadic Templates)顾名思义就是参数类型和个数可以改变的模板。
 *		变参模板是类型安全的，而且它可以让类似功能的实现得到极大简化。
 *		对于大多数程序员来说可能很少去编写模板库，但是新的可变参数的容器 std::tuple
 *		大多数都会用到。tuple 就是一个包含任意多个不同类型的数据成员的集合，就像一个
 *		增强版的 std::pair。
 *
 *		虽然变参模板无比拉风，但是平时编程时却不容易用到，tuple灵活强大，但是只用在
 *		函数返回值上，也未免大财小用，而且用多了会降低代码的可读性。在项目中，有需求
 *		要测试触发 signal 的功能，需要一个 slot 的 mock，signal 可能传递不同个数不同
 *		类型的参数，终于”以权谋私”用上了 Variadic Templates 和 tuple。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-12-26
 */

#include <cstdint>
#include <cstdlib>
#include <iostream>		/* std::cout, std::endl */
#include <tuple>		/* std::tuple, std::get, std::tie, std::ignore */

int main(void) {
	std::tuple<int, char> foo(10, 'x');
	auto bar = std::make_tuple("test", 3.1f, 14, 'y');

	std::get<2>(bar) = 100;		// access element

	int myint;
	char mychar;
	std::tie(myint, mychar) = foo;								// unpack elements
	std::tie(std::ignore, std::ignore, myint, mychar) = bar;	// unpack (with ignore)

	mychar = std::get<3>(bar);

	std::get<0>(foo) = std::get<2>(bar);
	std::get<1>(foo) = mychar;

	std::cout << "foo contains:" << std::endl;
	std::cout << "<0>" << std::get<0>(foo) << std::endl;	// 100
	std::cout << "<1>" << std::get<1>(foo) << std::endl;	// y

	return EXIT_SUCCESS;
}
