/**
 * @file main.cpp
 * @Synopsis  swap 技巧，除去多余容量。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-04-22
 */
#include <cstdlib>
#include <iostream>
#include <vector>

class Contestant {};
typedef std::vector<Contestant> ContestantVec;

int main(void) {
	ContestantVec contestants;
	Contestant contestant;
	for (int i = 0; i != 100; ++i) {
		contestants.push_back(contestant);
	}
	std::cout << contestants.capacity() << std::endl;			/// 128
	/// 区间删除(全部清空)
	contestants.erase(contestants.begin(), contestants.end());
	std::cout << contestants.capacity() << std::endl;			/// 128
	/// swap 去除多余容量
	ContestantVec tempVec;
	//ContestantVec(contestants).swap(contestants);				// 去除多余容量 
	//ContestantVec().swap(contestants);						// 相当于 clear(), 并清除容量
	tempVec.swap(contestants);									// 互换，并将 contestants 调用 clear()，并清除容量
	std::cout << contestants.capacity() << std::endl;			/// 0
	std::cout << tempVec.capacity() << std::endl;				/// 128
	/// 原先指向容器中的元素的迭代器、指针和引用仍然有效，并指向同样的元素，但是这些元素已经在另外的一个容器中。
	return EXIT_SUCCESS;
}

