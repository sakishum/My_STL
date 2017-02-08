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

bool qualityCompare(const Widget &lhs, const Widget &rhs) {
	bool ret = false;
	if (lhs.getData() < rhs.getData()) { 
		ret = true;
	}
	return ret;
}

int main(void) {
	std::vector<Widget> vw;
	Widget w1(1);
	vw.push_back(w1);
	Widget w2(21);
	vw.push_back(w2);
	Widget w3(45);
	vw.push_back(w3);
	Widget w4(34);
	vw.push_back(w4);
	Widget w5(23);
	vw.push_back(w5);
	Widget w6(16);
	vw.push_back(w6);
	Widget w7(20);
	vw.push_back(w7);

	for (auto &iter : vw) {
		std::cout << iter.getData() << ", ";
	}
	std::cout << std::endl;

	auto begin(vw.begin());
	auto end(vw.end());

	// std::nth_element 非稳定的排序算法

	// 查找一个区间的中间值
	auto goalPosition = begin + vw.size()/2;

	std::nth_element(begin, goalPosition, end, qualityCompare);
	std::cout << "goalPosition: " << goalPosition->getData() << std::endl;

	for (auto &iter : vw) {
		std::cout << iter.getData() << ", ";
	}
	std::cout << std::endl;

	// 查找某个特定百分比上的值
	std::vector<Widget>::size_type goalOffset = 0.25 * vw.size();
	std::nth_element(begin, begin + goalOffset, end, qualityCompare);
	// 现在 begin + goalOffset 所指的元素具有 75% 的质量
	std::cout << "goalPosition: " << (begin + goalOffset)->getData() << std::endl;

	for (auto &iter : vw) {
		std::cout << iter.getData() << ", ";
	}
	std::cout << std::endl;

	double rate = 0.48f;
	int value = static_cast<int>(rate * 100);
	std::cout << "value: " << value;

	return EXIT_SUCCESS;
}
