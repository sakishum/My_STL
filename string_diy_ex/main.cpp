#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

// 避免浅拷贝，实现深拷贝
class String {
public:
	String(void) : data_(new char[1]) {
		std::cout << "默认构造函数 1" << std::endl;
		data_[0] = '\0';
	}
	// const 
	explicit String(const char *data) : data_(new char[strlen(data) + 1]) {
		std::cout << "拷贝构造函数 1" << std::endl;
		strcpy(data_, data);
	}
	explicit String(const String &rhs) : data_(new char[rhs.size() + 1]) {
		std::cout << "拷贝构造函数 2" << std::endl;
		strcpy(data_, rhs.c_str());
	}
	explicit String(String &rhs) : data_(new char[rhs.size() + 1]) {
		std::cout << "拷贝构造函数 3" << std::endl;
		strcpy(data_, rhs.c_str());
	}
	String(String &&rhs) : data_(rhs.data_) {
		std::cout << "拷贝构造 2" << std::endl;
		rhs.data_ = nullptr;
	}
	~String(void) {
		delete [] data_;
		data_ = nullptr;
	}
	// pass by value
	// 1) 把源对象拷贝到了 rhs 里
	// 2）rhs 随想和 this 对象做一下交换，仅限指针
	// 3）返回 this 对象
	String &operator=(String rhs) {
		std::cout << "赋值运算重载 1" << std::endl;
		swap(rhs);
		return *this;
	}
	// use of overloaded operator '=' is ambiguous (with operand types 'String' and 'String')
	String &operator=(String &&rhs) {
		std::cout << "赋值运算重载 2" << std::endl;
		 swap(rhs);
		 return *this;
	}

	size_t size(void) const {
		return strlen(data_);
	}

	const char *c_str(void) const {
		return data_;
	}

	void swap(String &rhs) {
		std::cout << "Swap() called" << std::endl;
		std::swap(data_, rhs.data_);
	}

private:
	char *data_;
};

String getTemp(void) {
	String t;
	std::cout << "Resource  from " << __func__ << ": " << std::hex << &t << std::endl;;
	return t;
}

int main(int, char**) {
	String str(String("Hello "));
#if 0
	String str("Hello1 ");
	String str2(str);	// 调用了拷贝构造函数
	String str1 = str;	// 调用了拷贝构造函数, 最好写成 str1(str)
	String str3;
	str3 = str;			// 调用了赋值运算符重载函数
	// 从无到有是调用构造函数，从有到有调用的是赋值运算。
#endif
	//String str4;
	//str4 = getTemp();
#if 0	
	std::cout << "1111" << std::endl;
	{
		String str5 = getTemp();
		std::cout << "Resource  from " << __func__ << ": " << std::hex << &str5 << std::endl;;
	}
	std::cout << "2222" << std::endl;
#endif
	//std::cout << "Str1: " << str1.c_str() << std::endl;
	//std::cout << "str1.size(): " << str1.size() << std::endl;
	//std::cout << "Str2: " << str2.c_str() << std::endl;
	//std::cout << "Str3: " << str3.c_str() << std::endl;
	//std::cout << "Str4: " << str4.c_str() << std::endl;
	exit(EXIT_SUCCESS);
}
