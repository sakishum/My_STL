/**
 * @file main.cpp
 * @Synopsis  std::copy 只负责复制，不负责申请空间，所以复制前必须有足够的空间。
 *			如果把一个序列（squence）拷贝到一个容器（container）中去，通常使用 std::copy 算法。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-09-25
 */
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

#define MAX_SIZE(x) static_cast<int>(sizeof(x)/sizeof(x[0]))

typedef std::vector<int> ivec;

int main(int, char**) {
	int a[5] = {1,2,3,4,5};
	int b[3] = {0};
	//将数组 a 中的元素向左移动一位 
	std::copy(a+1, a+3, b);
	std::cout << "a: " << std::endl;
	for (int j = 0; j != MAX_SIZE(a); ++j) {
		std::cout << a[j] << " ";
	}
	std::cout << std::endl;
	std::cout << "b: " << std::endl;
	for (int j = 0; j != MAX_SIZE(b); ++j) {
		std::cout << b[j] << " ";
	}
	std::cout << std::endl;

	ivec temp;
	//ivec temp(4);
	// 这行代码，在这里一定要先为 vector 分配空间，否则程序会崩，这是初学者经常犯的一个错误
	temp.resize(5);
	//将数组 a 中的 4 个元素复制到 vector 容器中
	std::copy(a, a+4, &temp.front());
	std::cout << "ivec: " << std::endl;
	std::for_each(temp.begin(), temp.end(), [](int &item){
				std::cout << item << " ";
			});
	std::cout << std::endl;

	//copy函数最大的威力是结合标准输入输出迭代器的时候
	// 从标准输入设备读入整数
	// 直到输入的是非整型数据为止 请输入整数序列，按任意非数字键并回车结束输入  
	temp.clear();
	std::cout << "Please input element: " << std::endl;
	std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(),
			std::back_insert_iterator<ivec>(temp));

	// 输出容器里的所有元素，元素之间用空格隔开  
	std::cout << "Output: " << std::endl;
	std::copy(temp.begin(), temp.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	exit(EXIT_SUCCESS);
}

/*
 * 1. 单次(single-pass)
 * 2. 输出(output)
 * 3. 可选的分隔符(Optional delimiter)
 * 4. ++为空操作(Incrementing the std::ostream_iterator is a no-op)
 * std::ostream_iterator is a single-pass output iterator that writes successive objects of type T into the std::basic_ostream object for which it was constructed, using operator<<. Optional delimiter string is written to the output stream after every write operation. The write operation is performed when the iterator (whether dereferenced or not) is assigned to. Incrementing the std::ostream_iterator is a no-op. 
 * 
 * */
