#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <cassert>

int32_t mystrcmp(const char *dst, const char *src) {
	int ret = 0;
	while (!(ret = (unsigned char)*src - (unsigned char)*dst) && *dst != '\0') {
		++src;
		++dst;
	}
	if (ret > 0) {
		return 1;
	} else if (ret < 0) {
		return -1;
	}
	return ret;
}

size_t mystrlen(const char *str) {
	assert(nullptr != str);
	const char *p = str;
	while (*p != '\0') {
		++p;
	}
	return (p - str);
}

void mystrcpy(char *dst, const char *src) {
	assert(nullptr != dst && nullptr != src);
	while (*src != '\0') {
		*dst = *src;
		++src;
		++dst;
	}
	*dst = '\0';
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
	String &operator=(String rhs) {
		swap(rhs);
		return *this;
	}
	String &operator=(String &&rhs) {
		swap(rhs);
		return *this;
	}
	
	size_t size(void) const {
		return mystrlen(data_);
	}
	const char *c_str(void) const {
		return data_;
	}
	void swap(String &rhs) {
		std::swap(data_, rhs.data_);
	}
	char operator[](size_t pos) const {
		return data_[pos];
	}
	friend std::ostream &operator<<(std::ostream &output, String &rhs) {
		output << rhs.c_str();
		return output;
	}

private:
	char *data_;
};

auto main(int32_t, char**) -> int32_t {
	String str("aabbccddeeff");
	std::cout << str << std::endl;
	exit(EXIT_SUCCESS);
}
