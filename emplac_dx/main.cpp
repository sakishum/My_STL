/**
 * @file main.cpp
 * @Synopsis  Emplace 的实现，变参模板 + 右值引用。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-08-25
 */

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// 结合右值引用，变参模板在 STL 中应用广泛，例如 vector 中的 emplace 函数族
// (每个 STL 容器都提供了适当接口的 emplace* 函数), 用来使用其参数在内部内存
// 单元上直接构造对象，不但避免了不必要的内存拷贝，还可以省去临时对象的构造。

//template <typename... Args>
//void std::vector<T>::emplace_back(Args&&... args);

auto main(int, char**) -> int32_t {
	std::vector<std::string> v;
	// 内部内存上使用 placement new 操作符，直接调用 std::string(szie_t n, char c) 来构造函数。
	v.emplace_back(10, '*');
	
	//typedef std::vector<std::string>::value_type vtype;
	//std::for_each(v.begin(), v.end(), [&](vtype &it){ std::cout << it << std::endl;});
	std::for_each(v.begin(), v.end(), [](const std::string &it){ std::cout << it << std::endl;});
	exit(EXIT_SUCCESS);
}

