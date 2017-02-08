/**
 * @file main.cpp
 * @Synopsis  相比使用 std::map 的设计，通常会运行的更快而且使用更少的内存。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-04-28
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

typedef std::pair<std::string, int> Data;
class DataCompare {
public:
	bool operator()(const Data &lhs, const Data &rhs) const {
		return keyLess(lhs.first, rhs.first);
	}

	bool operator()(const Data &lhs, const Data::first_type &key) const {
		return keyLess(lhs.first, key);
	}

	bool operator()(const Data::first_type &key, const Data &rhs) const {
		return keyLess(key, rhs.first);
	}

private:
	bool keyLess(const Data::first_type &k1, const Data::first_type &k2) const {
		return k1 < k2;
	}
};  // class DataCompare

std::ostream& operator<<(std::ostream &s, const Data &p) {
    s << "("<< p.first << ", " << p.second << ")";
	return s;
}

typedef std::vector<Data> VMap;
int main(void) {
	VMap vd;
	/// 设置阶段：插入大量数据，几乎所有操作都是插入和删除
	vd.push_back(std::make_pair("c", 4));
	vd.push_back(std::make_pair("d", 3));
	vd.push_back(std::make_pair("a", 2));
	vd.push_back(std::make_pair("b", 1));

	std::sort(vd.begin(), vd.end(), DataCompare());
	for (const auto &iter : vd) {
		std::cout << "("<< iter.first << ", " << iter.second << ")" << std::endl;
	}
	
	/// 查找阶段：查询该数据结构以查找到特定的内容，几乎全是查找操作，很少或几乎没有插入或删除操作。
	std::string str("c");
	VMap::iterator iter = std::lower_bound(vd.begin(), vd.end(), str, DataCompare());
	if (iter != vd.end()) {
		std::cout << "The data is:" << std::endl;
		std::cout << "("<< (*iter).first << ", " << (*iter).second << ")" << std::endl;
	}

	/// 重组阶段：改变数据结构的内容，或许是删除所有的当前数据。
	vd.clear();
	std::sort(vd.begin(), vd.end(), DataCompare());

	return EXIT_SUCCESS;
}
