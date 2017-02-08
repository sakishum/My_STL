#include <cstdlib>
#include <list>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>

class CItem {
public:
	CItem(int id, int data): m_id(id), m_data(data) {
	}
	~CItem(void) {
	
	}
	void setData(int data) {
		m_data = data;
	}
	int getData(void) const {
		return m_data;
	}
	int getid(void) const {
		return m_id;
	}

private:
	int m_id;
	int32_t m_data;
};

typedef boost::shared_ptr<class CItem> CItemPtr;
typedef std::list<CItemPtr> CItemSortList;

typedef boost::mt19937                     	ENG;     // Mersenne Twister
typedef boost::uniform_int<int32_t> 		DIST;    // uniform_int Distribution
typedef boost::variate_generator<ENG,DIST> 	GEN;     // Variate generator

int32_t produceInteger(int32_t min, int32_t max, uint32_t seed) {                                                                   
    ENG  eng(seed); 
    DIST dist(min, max);
    GEN  gen(eng, dist); 
    return gen();
}

int main(void) {
	CItemSortList itemlist;
	CItemPtr pitem2 = CItemPtr(new CItem(1, 6));
	std::cout << "data: " << pitem2->getData() << std::endl;
	itemlist.push_back(pitem2);
	auto iter = *std::max_element(itemlist.begin(), itemlist.end(), [](CItemPtr a, CItemPtr b) { return a->getid() < b->getid(); });
	std::cout << "ID : " << iter->getid() << std::endl;

	for (int i = 5; i != 1; --i) {
		CItemPtr pitem = CItemPtr(new CItem(i, produceInteger(1, 100, i)));
		std::cout << "data: " << pitem->getData() << std::endl;
		itemlist.push_back(pitem);
	}

	CItemPtr pitem1 = CItemPtr(new CItem(0, 6));
	std::cout << "data: " << pitem1->getData() << std::endl;
	itemlist.push_back(pitem1);
	
	// 获取长度
	std::cout << "size: " << itemlist.size() << std::endl;
	// 遍历 list 
	for (auto item : itemlist) {
		std::cout << item->getid() << ", " << item->getData() << std::endl;
	}
	std::cout << std::string(30, '_') << std::endl;
	// 根据 data 排序
	itemlist.sort([](CItemPtr a, CItemPtr b) { return a->getData() > b->getData(); });
	for (auto item : itemlist) {
		std::cout << item->getid() << ", " << item->getData() << std::endl;
	}
	
	auto iter1 = *std::max_element(itemlist.begin(), itemlist.end(), [](CItemPtr a, CItemPtr b) { return a->getid() < b->getid(); });
	std::cout << "ID : " << iter1->getid() << std::endl;


	return EXIT_SUCCESS;
}
