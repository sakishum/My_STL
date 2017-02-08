#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>

struct stDB_Hero_Rule_Extra {
	stDB_Hero_Rule_Extra(int32_t num, int32_t type) : num_(num), type_(type) { }
	int32_t num_;
	int32_t type_;
};

typedef std::map<int32_t, stDB_Hero_Rule_Extra>  DBHeroRule;

int main(void) {
	DBHeroRule HeroMap;
	// 插入（右值引用）
	HeroMap.emplace(2, stDB_Hero_Rule_Extra(1, 2));
	HeroMap.emplace(3, stDB_Hero_Rule_Extra(2, 3));
	HeroMap.emplace(4, stDB_Hero_Rule_Extra(3, 4));
	HeroMap.emplace(5, stDB_Hero_Rule_Extra(4, 5));
	HeroMap.emplace(6, stDB_Hero_Rule_Extra(5, 6));

	// 遍历
	std::for_each(HeroMap.begin(), HeroMap.end(), [&](DBHeroRule::value_type &info) {
			std::cout << "num: " << info.second.num_ << " type: " << info.second.type_ << std::endl;
			 });

	// 第一个元素
	DBHeroRule::iterator iter = HeroMap.begin();
	std::cout << iter->second.num_ << " " << iter->second.type_ << std::endl;;
	// 最后一个元素
	DBHeroRule::reverse_iterator riter = HeroMap.rbegin();
	std::cout << riter->second.num_ << " " << riter->second.type_ << std::endl;;
	
	// 循环删除
	// map 是关联容器，对于关联容器来说，如果某一个元素已经被删除，那么其对应的迭代器就失效了，不应该在被使用；
	// 否则会导致程序无定义行为。
	//for (DBHeroRule::iterator iter = HeroMap.begin(); iter != HeroMap.end(); ++iter) {
	for (DBHeroRule::iterator iter = HeroMap.begin(); iter != HeroMap.end();) {
		std::cout << iter->second.num_ << " " << iter->second.type_ << std::endl;
		HeroMap.erase(iter++);
		// or
		// iter = HeroMap.erase(iter);
	}

	std::cout << "Size: " << HeroMap.size() << std::endl;

	exit(EXIT_SUCCESS);
}
