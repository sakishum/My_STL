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

bool hasAcceptableQuality(const Widget &w) {
	bool ret = false;
	if (w.getData() > 20) {
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

	// std::partition 算法, 将所有满足某个特定条件的元素放在区间的前部
	auto goodEnd = std::partition(begin, end, hasAcceptableQuality);
	for (auto iter = begin; iter != goodEnd; ++iter) {
		std::cout << iter->getData() << ", ";
	}
	std::cout << std::endl;

	for (auto &iter : vw) {
		std::cout << iter.getData() << ", ";
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
