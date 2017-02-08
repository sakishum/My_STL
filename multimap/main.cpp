/**
 * @file main.cpp
 * @Synopsis  multimap 容器，它与 map 类似，所不同的是它允许重复键。
 *		这个属性使得 multimap 比预想的要更有用：比如在电话簿中相同的
 *		人可以有两个以上电话号码，文件系统中可以将多个符号链接映射到
 *		相同的物理文件，或DNS服务器可以将几个URLs映射到相同的IP地址。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-12-15
 */
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <map>			/* std::multimap */
#include <string>		/* std::string */
#include <iostream>		/* std::cout, std::endl */
#include <utility>		/* std::pair */
#include <algorithm>    /* std::for_each */

int main(void) {
	// Compare (<) function not required since it is built into string class.
	// else declaration would comparison function in multimap definition.
	// i.e. multimap<string, int, compare> m;
	typedef std::multimap<std::string, int32_t> multiMap;
	multiMap m;
	
	m.insert(std::make_pair("a", 1));
	m.insert(std::make_pair("c", 2));
	m.insert(std::make_pair("b", 3));
	m.insert(std::make_pair("b", 4));
	m.insert(std::make_pair("a", 5));
	m.insert(std::make_pair("b", 6));

	// 注意：map 的键不能修改
	std::cout << "Number of elements with key a: " << m.count("a") << std::endl;
	std::cout << "Number of elements with key b: " << m.count("b") << std::endl;
	std::cout << "Number of elements with key c: " << m.count("c") << std::endl;
	std::cout << "Size of elements: " << m.size() << std::endl;

	std::cout << "Elements in m: " << std::endl;
	for (multiMap::iterator iter = m.begin(); iter != m.end(); ++iter) {
		std::cout << " [" << (*iter).first << ", " << (*iter).second << "] " << std::endl;
	}

	std::cout << std::string(30, '-') << std::endl;
	std::pair<multiMap::iterator, multiMap::iterator> ppp;
	// equal_range(b) returns pair<iterator,iterator> representing the range
	// of element with key b
	ppp = m.equal_range("b");

	// check empty
	if (ppp.first == ppp.second) {
		std::cout << "Empty." << std::endl;
	} else {
		std::cout << "Not Empty." << std::endl;
	}

	// check the count of "b"
	std::cout << "The count of \'b\' is "<< m.count("b") << std::endl;
	std::cout << "The count of \'z\' is "<< m.count("z") << std::endl;

	// Loop through of maps of key "b"
	std::cout << "Range of \"b\" elements: " << std::endl;
	for (multiMap::iterator iter = ppp.first; iter != ppp.second;) {
		std::cout << " [" << (*iter).first << ", " << (*iter).second << "] " << std::endl;
		if ((*iter).second == 4) {
		iter = m.erase(iter);
		} else {
			++iter;
		}
	}
	std::cout << "The count of \'b\' is "<< m.count("b") << std::endl;

	std::cout << "Elements in m: " << std::endl;
	for (multiMap::iterator iter = m.begin(); iter != m.end(); ++iter) {
		std::cout << " [" << (*iter).first << ", " << (*iter).second << "] " << std::endl;
	}
	
	m.clear();

	return EXIT_SUCCESS;
}
