/**
 * @file main.cpp
 * @Synopsis  std::map 关联容器，用来存储key-value数据。插入的数据是自动排序的，
 *		默认的排序方式是升序。map通常是以平衡二叉查找树来实现的，因此map对插入，
 *		删除，查找能保证log(N)的时间复杂度。对于海量的数据的插入和查询，map是一
 *		个不错的选择。Map和multimap对象包涵了键和各个键有关的值，键和值的数据类
 *		型是不相同的，这与set不同。set中的key和value是Key类型的，而map中的key和
 *		value是一个pair结构中的两个分量。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-01-20
 */

#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>

// c++std map key with ascending order (default)	升序
typedef std::map<uint32_t, std::string> ASCMap;
// c++std map key with descending order				降序
typedef std::map<uint32_t, std::string, std::greater<uint32_t> > DECMap;

template<typename T>
class PrintElem {
public:
	void operator()(const T &elem) {
		std::cout << elem.first << ", " << elem.second << std::endl;
	}
};

int main(void) {
	DECMap dmap;
	// 三种插入方式：
	// 直接下标插入
	// 存在一个性能的问题: 重复插入，会将原先的每个赋值都赋为初始值，再赋值为最后插入的值，
	// 如果元素是类对象，则开销比较大。
	dmap[4] = std::string("aaa");
	dmap[2] = std::string("aaa");
	dmap[8] = std::string("aaa");
	dmap[3] = std::string("aaa");
	dmap[1] = std::string("aaa");
	// 使用 value_type 插入数据:
	dmap.insert(DECMap::value_type(5, "bbbb"));
	std::cout << "Key: " << 5 << ", Value: " << dmap[5] << std::endl;
	//dmap[1] = std::string("aaalll");			// 插入失败
	dmap.insert(std::make_pair(1, "aaalll"));	// 插不进去
	std::cout << "insert_ dmap[1] : " << dmap[1] << std::endl;
	dmap[1] = std::string("bbb");				// 替换掉原先的值
	std::cout << "[]    _ dmap[1] : " << dmap[1] << std::endl;

	// rbegin 与 rend 的用法
	// 获取 map 最后一个元素的 value
	auto last = dmap.rbegin();
	if (last != dmap.rend()) {
		std::cout << "Last: " << last->first << ", " << last->second << std::endl;
	}

	// 用后两种方法可以避免开销
	// Use std::make_pair() function:
	dmap.insert(std::make_pair(6, std::string("cccc")));

	// 插入一个元素(不执行copy或move操作)到map
	// template <class... Args> pair<iterator, bool> emplace(Args&&... args)
	dmap.emplace(19, std::move(std::string("vcb")));

	// Directly use std::pair constructor:
	dmap.insert(std::pair<uint32_t, std::string>(5, std::string("bbb")));
	// 删除 key 为 3 的元素
	dmap.erase(dmap.find(3));

	for (auto &kv : dmap) {
		std::cout << kv.first << std::endl;
	}
	std::cout << std::string(30, '-') << "PrintElem<std::pair<int, std::string>>()" << std::endl;
	// std::map operator(<) 是如何比较大小的？ 成对成对的比较，从第一个元素开始，先比较它
	// 的 key，key 如果相等再比较 value. value 如果也相等，再去比较第二个元素的 key，依次
	// 类推。
	std::for_each(dmap.begin(), dmap.end(), PrintElem<std::pair<int, std::string>>());
	std::cout << std::string(30, '-') << "PrintElem<DECMap::value_type>()" << std::endl;
	std::for_each(dmap.begin(), dmap.end(), PrintElem<DECMap::value_type>());
	std::for_each(dmap.begin(), dmap.end(), [](DECMap::value_type &t){ std::cout << t.first << ", " << t.second << std::endl; });
	//std::for_each(dmap.begin(), dmap.end(), PrintElem<DECMap::value_type>());
	return EXIT_SUCCESS;
}
