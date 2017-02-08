/**
 * @file main.cpp
 * @Synopsis  Example of std::find for boost::shared_ptr.
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-12-16
 */

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>    // std::find, std::find_if
#include <iterator>     // std::distance
#include <list>
#include <map>
#include <vector>
#include <string>
#include <boost/smart_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <unordered_map>

#define xHashMap std::unordered_map

struct Data {
	Data(uint64_t uid, int32_t exp) : m_uid(uid), m_exp(exp) {
		// Empty, Do Nothing.
	}
	int32_t getExp(void) const {
		return m_exp;
	}
	uint64_t m_uid;
	int32_t m_exp;
};  // struct Data

typedef boost::shared_ptr<Data> DataPtr;
typedef std::vector<DataPtr> DataPtrVec;
typedef xHashMap<uint64_t, DataPtr> DataPtrMap;
typedef std::list<DataPtr> DataPtrList;

bool is_parameter(DataPtr ptr, uint64_t roleid) {
   return (ptr->m_uid == roleid);
}

int main(void) {
	DataPtrMap datamap;
	DataPtr ptr1(new Data(123, 100));
	DataPtr ptr2(new Data(124, 200));	// Get
	DataPtr ptr3(new Data(125, 300));
	DataPtr ptr4(new Data(126, 400));
	DataPtr ptr5(new Data(127, 500));
	DataPtr ptr6(new Data(128, 600));
	DataPtr ptr7(new Data(129, 700));
	DataPtr ptr8(new Data(130, 800));	// Ignore

	datamap.insert(std::make_pair(1, ptr1));
	datamap.insert(std::make_pair(1, ptr2));

	for (auto &iter : datamap) {
		std::cout << iter.second->getExp();
	}
	
	return EXIT_SUCCESS;
}
