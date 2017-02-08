/**
 * @file main.cpp
 * @Synopsis  Example for capacity of vector in CPP.
 *			  Example for list of STL in CPP.
 *			  容量/大小的区别：
 *			  std::vector::capacity() : 指容器的能容纳多少个。
 *			  std::vector::size() : 指容器当前已装多少个。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-03-17
 */

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>

int main(void) {
	std::vector<int> ivec;
	printf("The empty vector<int> size is %zu\n", sizeof(ivec));		// 24
	printf("The empty vector<int> max size is %zu\n", ivec.max_size());	// 4611686018427387903
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);
	ivec.push_back(4);
	/// capacity()返回容量，是当前的vector所实际能够容纳的元素的数量
	printf("The std::vector<int> capacity is %zu\n", ivec.capacity());	// 4
	printf("The std::vector<int> is empty is %d\n", ivec.empty() ? 1 :0);	// 1
	/// 手动设置 容量, reserve（）函数预留相当大的容量，以避免一再重新配置内存
	ivec.reserve(50);
	ivec.reserve(25);	/// 容量不会改变， 还是 50
	//ivec.resize(2*ivec.size(), 99);	/// real size 翻倍，并初始化为 指定值（99）
	printf("ivec.resize(2*ivec.size(), 99)\n");
	printf("The std::vector<int> size is %zu\n", ivec.capacity());	// 50
	printf("The std::vector<int> real size is %zu\n", ivec.size());	// 4
	ivec.clear();
	/// Vector的容量不会缩减，即使使用clear（）函数，清空Vector的所有元素，Vector的真正占用内存不会减少
	printf("The empty vector<int> size is %zu\n", sizeof(ivec));		// 24
	printf("The std::vector<int> capacity is %zu\n", ivec.capacity());	// 50
	printf("The std::vector<int> is empty is %d\n", ivec.empty() ? 1 :0);	// 1
	/// 技巧：清空vector, 原因： 两个Vector交换内容后，两者的容量也会互换
	std::vector<int> temp;
	ivec.swap(temp);
	printf("The std::vector<int> capacity is %zu\n", ivec.capacity());	// 0

	std::list<int> ilist1;
	std::list<int> ilist2;
	ilist1.push_back(1);
	ilist1.push_back(2);
	ilist1.push_back(3);
	ilist1.push_back(4);
	ilist1.push_back(5);
	printf("The std::list<int> size is %zu\n", ilist1.size());	// 5
	/// 将ilist1 中的元素赋给 ilist2
	while (!ilist1.empty()) {
		ilist2.push_back(ilist1.back());
		ilist1.pop_back();
	}
	/// 遍历 ilist2 
	std::list<int>::iterator iter = ilist2.begin();
	while (iter != ilist2.end()) {
		printf("The data is %d\n", *iter);
		++iter;
	}

	return EXIT_SUCCESS;
}
