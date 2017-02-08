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
	uint64_t m_uid;
	int32_t m_exp;
};  // struct Data

typedef boost::shared_ptr<Data> DataPtr;
typedef std::vector<DataPtr> DataPtrVec;
typedef xHashMap<uint64_t, DataPtr> DataPtrMap;

bool is_parameter(DataPtr ptr, uint64_t roleid) {
   return (ptr->m_uid == roleid);
}

int main(void) {
	DataPtrMap smap;
	DataPtr ptr1(new Data(123, 100));
	DataPtr ptr2(new Data(124, 200));	// Get
	DataPtr ptr3(new Data(125, 300));
	DataPtr ptr4(new Data(126, 400));
	DataPtr ptr5(new Data(127, 500));	// Ignore

	smap[1] = ptr1;
	smap[3] = ptr2;
	smap[5] = ptr3;
	smap[7] = ptr4;
	smap[9] = ptr5;

	// boost::bind
	//auto iter = std::find_if(svec.begin(), svec.end(), boost::bind(is_parameter, _1, 124)); 
	// Lambda
	auto iter = std::find_if(smap.begin(), smap.end(), [=](const std::pair<uint64_t, DataPtr> &v)->bool{ return v.second->m_uid == 126; }); 
	if (iter != smap.end()) {
		std::cout << "The target is: " << iter->first << std::endl;
		std::cout << "The distance is: " << std::distance(smap.begin(), iter) << std::endl;
	}
	
	return EXIT_SUCCESS;
}
