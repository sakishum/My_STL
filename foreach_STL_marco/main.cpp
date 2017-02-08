#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>		/* typeof */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

// 宏无法处理逗号， e.g. foreach(m,it,map<unsigned,string>)	 ERROR
#define foreach(container, it, type)\
	for (auto it = (container).begin(); it != (container).end(); ++it)
	//for (typeof((container).begin()) it = (container).begin(); it != (container).end(); ++it)
	
typedef std::set<std::string> strSet;

int main(void) {
	strSet sset;
	sset.insert("w");
	sset.insert("a");
	sset.insert("n");
	sset.insert("w");

	std::cout << "set 的 size 值为 " << sset.size() << std::endl;
	std::cout << "set 的maxsize 为 " << sset.max_size() << std::endl;
	std::cout << "set 的第一个元素 " << *sset.begin() << std::endl;

	foreach(sset, it, strSet) {
		std::cout << *it << std::endl;	// a n w
	}
	return EXIT_SUCCESS;
}
