#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

class String {
public:
	String(void) : data_(new char[1]) {
		data_[0] = '\0';
	}

	String(const char *str) : data_(new char[strlen(str) + 1]) {
		strcpy(data_, str);
	}

	String(const String &rhs) : data_(new char[rhs.size() + 1]) {
		strcpy(data_, rhs.c_str());
	}

	String(String &&rhs) : data_(rhs.data_) {
		rhs.data_ = nullptr;
	}

	// pass by value
	String &operator=(String rhs) {
		swap(rhs);
		return *this;
	}

	String &operator=(String &&rhs) {
		swap(rhs);
		return *this;
	}

	~String(void) {
		delete [] data_;
	}

	size_t size(void) const {
		return strlen(data_);
	}

	char operator[](const size_t pos) const {
		return data_[pos];
	}

	const char *c_str(void) const {
		return data_;
	}

	void swap(String &rhs) {
		std::swap(data_, rhs.data_);
	}

	//运算符“<<”重载为友元函数
	friend std::ostream &operator << (std::ostream& output, String& str) {
		output << str.c_str();
		return output;
	}

private:
	char *data_;
};  // class String

auto main(int, char**) -> int {
	String str = "AABBCCC";
	std::cout << "size: " << str.size() << std::endl;
	std::cout << "data: " << str.c_str() << std::endl;
	std::cout << "str[3]: " << str[3] << std::endl;
	std::cout << "ostream: " << str << std::endl;

	exit(EXIT_SUCCESS);
}
