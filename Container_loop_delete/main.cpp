#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>

typedef std::vector<int> IVEC;
typedef std::map<int, int> IMAP;

bool badValue(int value) {
	bool ret = false;
	std::cout << value << std::endl;
	if (value < 0) {
		ret = true;
	}
	return ret;
}

int main(void) {
	// AssocContainer:
	IMAP imap;
	imap.insert(std::make_pair(1, -123));
	imap.insert(std::make_pair(2, 234));
	imap.insert(std::make_pair(3, -345));
	imap.insert(std::make_pair(4, 456));
	imap.insert(std::make_pair(5, -567));
	for (auto iter = imap.begin(); iter != imap.end(); /* 什么也不做 */) {
		if (badValue(iter->second)) {
			// 标准关联容器, erase 的返回值类型是 void
			imap.erase(iter++);
		} else {
			++iter;
		}
	}
	std::cout << std::string(30, '_') << std::endl;
	for (auto iter : imap) {
		std::cout << iter.second << std::endl;
	}
	std::cout << std::string(30, '_') << std::endl;

	// Seq Contaimer:
	IVEC ivec = {-123, 234, -345, 456, -567};
	for (auto iter = ivec.begin(); iter != ivec.end();/* 什么也不做 */) {
		if (badValue(*iter)) {
			iter = ivec.erase(iter);
		} else {
			++iter;
		}
	}

	std::cout << std::string(30, '_') << std::endl;
	for (auto &item : ivec) {
		std::cout << item << std::endl;
	}
	return EXIT_SUCCESS;
}
