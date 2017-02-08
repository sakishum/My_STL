/**
 * @file main.cpp
 * @Synopsis  一个String类的完整实现必须很快速写出来（注意：赋值构造，operator=是关键）。
 *			  Note: 
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-09-15
 */
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

class String {
public:
	String(void) : data_(new char[1]) {
		data_[0] = '\0';
	}
	String(const char *pdata) : data_(new char[strlen(pdata) + 1]) {
		strcpy(data_, pdata);
	}
	String(const String &str) : data_(new char[str.size() + 1]) {
		strcpy(data_, str.c_str());
	}
	String(String &&rhs) : data_(rhs.data_) {
		rhs.data_ = nullptr;
	}
	~String(void) {
		// 同时 delete [] NULL 和delete NULL 是安全的，但是同一个非 NULL 地址 delete 两次是致命的。
		delete [] data_;
	}
	// pass by value
	String &operator=(String rhs) {		//	<---
		swap(rhs);
		return *this;
	}
	String &operator=(String &&rhs) {
		swap(rhs);
		return *this;
	}
	// Accessor
	size_t size(void) const {
		return strlen(data_);
	}
	const char *c_str(void) const {
		return data_;
	}
	void swap(String &rhs) {
		std::swap(data_, rhs.data_);	// <---
	}

private:
	char *data_;
};  // class String

// test:
void foo(String x) {
	std::cout << x.c_str() << std::endl;
}

void bar(const String &x) {
	std::cout << x.c_str() << std::endl;
}

String baz(void) {
	String ret("World");
	return ret;
}

auto main(int32_t, char**) -> int32_t {
	String str(String("Hello "));
	//String s0;
	//String s1("Hello ");
	//String s2(s0);
	//String s3 = s1;
	//s2 = s1;

	//foo(s1);
	//bar(s1);
	//foo("Temporary");
	//bar("Temporary");
	//String s4 = baz();

	//std::vector<String> svec;
	//svec.emplace_back(s0);
	//svec.emplace_back(baz());
	//svec.emplace_back("good job");

	//std::for_each(svec.begin(), svec.end(), [] (String &str) { std::cout << str.c_str() << std::endl; });
	exit(EXIT_SUCCESS);
}
