/**
 * @file main.cpp
 * @Synopsis  为包含指针的关联容器指定比较类型。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-04-26
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <set>
#include <iterator>     // std::ostream_iterator
#include <algorithm>    // std::copy std::transform

struct DereferenceLess {
	// 将作为一个比较函数，用于按照字符串的值对 string* 指针进行排序
	template<typename PtrType>
	bool operator()(PtrType pT1, PtrType pT2) const {
		return *pT1 < *pT2;
	}

	// 当向该类型的函数子传入PtrType* 时，他们返回 const PtrType& 
	template<typename PtrType>
	const PtrType& operator()(const PtrType *ptr) const {
		return *ptr;
	}
};

int main(void) {
	std::set<std::string*, DereferenceLess> ssp;					// ssp = "set of string ptrs"
	ssp.insert(new std::string("Anteater"));
	ssp.insert(new std::string("Wombat"));
	ssp.insert(new std::string("Lemur"));
	ssp.insert(new std::string("Penguin"));

	// 避免编写自己的循环, 使用算法代替循环
	std::transform(ssp.begin(), ssp.end(),							// 通过解除指针引用，“转换“
			std::ostream_iterator<std::string>(std::cout, "\n"),	// ssp 中每个元素，并把结果
			DereferenceLess());										// 写到 std::cout
	return EXIT_SUCCESS;
}

