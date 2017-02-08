/**
 * @file main.cpp
 * @Synopsis  排序的 vector 替代关联容器.
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-04-28
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

class Widget {
public:
	Widget(void) { }
	Widget(int data) : m_data(data) {
	}
	
	int getData(void) const {
		return m_data;
	}
	
	bool operator==(const Widget &rhs) const {
		bool ret = false;
		if (m_data == rhs.getData()) {
			ret = true;
		}
		return ret;
	}

	bool operator<(const Widget &rhs) const {
		bool ret = false;  
		if (m_data < rhs.getData()) { 
			ret = true; 
		}
		return ret;
	}

private:
	int m_data;
};

std::ostream& operator<<(std::ostream &s, const Widget &p) {
	return s << p.getData();
}

int main(void) {
	std::vector<Widget> vw;
	Widget w1(1);
	vw.push_back(w1);
	Widget w2(34);
	vw.push_back(w2);
	Widget w3(45);
	vw.push_back(w3);
	Widget w4(23);
	vw.push_back(w4);
	Widget w5(23);
	vw.push_back(w5);

	// 排序
	std::sort(vw.begin(), vw.end());

	// 循环打印 Wiget 内的数据
	std::copy(vw.begin(), vw.end(), 
			std::ostream_iterator<Widget>(std::cout, "\n"));

	// 设置带查找的值
	Widget w(23);

	// 通过 binary_search 查找
	if (std::binary_search(vw.begin(), vw.end(), w)) {
		std::cout << "found!" << std::endl;; 
	} else {
		std::cout << "not found." << std::endl;
	}

	// 通过 equal_range 查找
	std::pair<std::vector<Widget>::iterator, 
		std::vector<Widget>::iterator> range 
			= std::equal_range(vw.begin(), vw.end(), w);
	if (range.first != range.second) {
		std::cout << "Found!" << std::endl;
	}

	// 通过 lower_bound 查找
	std::vector<Widget>::iterator iter =
		std::lower_bound(vw.begin(), vw.end(), w);
	// !(w < *iter) : 
	if (iter != vw.end() && !(w < *iter)) {
		std::cout << "Found!" << std::endl;
	}

	return EXIT_SUCCESS;
}
