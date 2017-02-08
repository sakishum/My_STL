#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

void mystrcpy(char *dst, const char *src) {
	assert(nullptr != src);
	while(*src != '\0') {
		*dst = *src;
		++src;
		++dst;
	}
	*dst = '\0';
}

size_t mystrlen(const char *src) {
	assert(nullptr != src);
	const char *p = src;
	while(*p != '\0') {
		++p;
	}
	return (p - src);
}

class String {
public:
	String(void) : data_(new char[1]) {
		data_[0] = '\0';
	}
	String(const char *str) : data_(new char[mystrlen(str) + 1]) {
		mystrcpy(data_, str);
	}
	String(const String &rhs) : data_(new char[rhs.size() + 1]) {
		mystrcpy(data_, rhs.c_str());
	}
	String(String &&rhs) : data_(rhs.data_) {
		rhs.data_ = nullptr;
	}
	~String(void) {
		delete [] data_;
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
	// accessor
	size_t size(void) const {
		return mystrlen(data_);
	}
	const char *c_str(void) const {
		return data_;
	}
	void swap(String &rhs) {
		std::swap(data_, rhs.data_);
	}
	char operator[](size_t pos) {
		return data_[pos];
	}
	friend std::ostream &operator << (std::ostream& output, const String& str) {
		output << str.c_str();
		return output;
	}

private:
	char *data_;
};

auto main(int, char**) -> int32_t {
	String str = String("AABB");
	std::cout << str << std::endl;
	exit(EXIT_SUCCESS);
}
