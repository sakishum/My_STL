#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

/*
 * 1) 能像 int 类型那样定义变量，并且支持赋值、复制；
 * 2）能用作函数的参数类型及返回类型；
 * 3）能作为标准库容器的元素类型，即 vector、list、deque 的 value_type 。
 * */

/*
 * 注意：
 * 1）首先选择数据成员，只有一个数据成员 char* data_, 容易实现，不容易出错;
 * 2) 其次决定支持那些操作，构造、析构、拷贝构造、赋值这几样肯定是要有的（之前叫 bigthree，现在叫 copy control）。
 * 3) 只在构造函数里面用 new char[]，析构函数里面用 delete [];
 * 4) 赋值操作符采用了<<C++ 编程规范>>推荐的现代写法;
 * 5）每个函数只有一两行代码，没有条件判断;
 * 6) 析构函数不必检查 data_ 是否为 NULL;
 * 7) 构造函数 String(const char *str) 没有检查 str 的合法性，这是一个永无止境的争论话题;
 * */

#include <utility>
#include <cstring>

class String {
public:
	String(void) 
		: data_(new char[1]) {
		data_[0] = '\0';
	}

	String(const char *str) 
		: data_(new char[strlen(str) + 1]) {
		strcpy(data_, str);
	}

	String(const String &rhs) 
		: data_(new char[rhs.size() + 1]) {
		strcpy(data_, rhs.c_str());
	}

	// C++11
	String(String &&rhs) 
		: data_(rhs.data_) {
		rhs.data_ = nullptr;
	}

	~String(void) {
		delete [] data_;
		data_ = nullptr;
	}

	// Pass by value
	String &operator=(String rhs) {
		swap(rhs);
		return *this;
	}

	// C++ 11
	String &operator=(String &&rhs) {
		swap(rhs);
		return *this;
	}
	
	// Accessors
	size_t size(void) const {
		return strlen(data_);
	}

	const char* c_str(void) const {
		return data_;
	}

	void swap(String &rhs) {
		std::swap(data_, rhs.data_);
	}

private:
	char *data_;
};  // class String

// ========================================================

// For test:
void foo(String x) {
	std::cout << x.c_str() << std::endl;
}

void bar(const String &x) {
	std::cout << x.c_str() << std::endl;
}

String baz(void) {
	String ret("word");
	return ret;
}

auto main(int32_t, char**) -> int32_t {
	String s0;
	String s1("Hello");
	String s2(s0);
	String s3 = s1;
	s2 = s1;

	foo(s1);
	bar(s1);
	foo("temporary");
	bar("temporary");
	String s4 = baz();

	std::vector<String> svec;
	svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(baz());
	svec.push_back("good job");

	std::for_each(svec.begin(), svec.end(), [&](std::vector<String>::value_type x){ std::cout << x.c_str() << std::endl; });

	std::cout << __PRETTY_FUNCTION__ << std::endl;
	exit(EXIT_SUCCESS);
}
