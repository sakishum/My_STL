/**
 * @file main.cpp
 * @Synopsis  Associative Container Erase Item.
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-09-04
 */

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <set>

auto main(int, char**) -> int32_t {
	std::multiset<int32_t> imset;
	imset.insert(3);
	imset.insert(2);
	imset.insert(3);
	imset.insert(3);
	imset.insert(5);
	std::multiset<int32_t>::iterator iter;
	int32_t x = 3;
	for (iter = imset.begin(); iter != imset.end();) {
		if (*iter == x) {
			//iter = imset.erase(iter);		// compile error in g++, but pass in Visual Studio
			// 解决兼容性问题
			imset.erase(iter++);			// 1) iterator temp = iter; 2) iter++; 3) erase(temp)  
		} else {
			++iter;
		}
	}

	for (iter = imset.begin(); iter != imset.end(); ++iter) {
		printf("%d\n", *iter);
	}

	exit(EXIT_SUCCESS);
}
