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
#include <algorithm>    // std::find
#include <vector>
#include <string>
#include <boost/smart_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

struct Data {
	Data(uint64_t uid, int32_t exp) : m_uid(uid), m_exp(exp) {
		// Empty, Do Nothing.
	}
	uint64_t m_uid;
	int32_t m_exp;
};  // struct Data

typedef boost::shared_ptr<Data> DataPtr;
typedef std::vector<DataPtr> DataPtrVec;

bool is_parameter(DataPtr ptr, uint64_t roleid) {
   return (ptr->m_uid == roleid);
}

int main(void) {
	DataPtrVec svec;
	DataPtr ptr1(new Data(123, 100));
	DataPtr ptr2(new Data(124, 200));	// Get
	DataPtr ptr3(new Data(125, 300));
	DataPtr ptr4(new Data(126, 400));
	DataPtr ptr5(new Data(124, 500));	// Ignore

	svec.push_back(ptr1);
	svec.push_back(ptr2);
	svec.push_back(ptr3);

	//auto iter = std::find_if(svec.begin(), svec.end(), boost::bind(is_parameter, _1, 124)); 
	// Lambda
	auto iter = std::find_if(svec.begin(), svec.end(), [=](DataPtr ptr)->bool{ return ptr->m_uid == 124; }); 
	if (iter != svec.end()) {
		std::cout << "The target is " << (*iter)->m_exp << std::endl;
	}
	
	return EXIT_SUCCESS;
}
