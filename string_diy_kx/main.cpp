#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <vector>
#include <algorithm>

// 递归实现获取字符串长度（免中间变量）
int32_t mystrlen(const char *str) {
	if (*str == '\0') {
		return 0;
	} else {
		return mystrlen(str + 1) + 1;
	}
}

// 带长度限制的字符串拷贝函数
const char *mystrncpy(char *dst, const char *src, int32_t len) {
	while (len > 0 && (*dst++ = *src++) != '\0') { 
		--len;
	}
	return dst;
}

class String {
public:
	String(void) : data_(new char[1]) {
		data_[0] = '\0';
	}
	String(const char *str) : data_(new char[mystrlen(str) + 1]) {
		mystrncpy(data_, str, mystrlen(str));
	}
	String(const String &rhs) : data_(new char[rhs.size() + 1]) {
		mystrncpy(data_, rhs.c_str(), rhs.size());
	}
	String(String &&rhs) : data_(rhs.data_) { }
	~String(void) {
		delete [] data_;
		data_ = NULL;
	}
	// 注意： pass by value
	String &operator=(String rhs) {
		swap(rhs);
		return *this;
	}
	String &operator=(String &&rhs) {
		swap(rhs);
		return *this;
	}
	char operator[](size_t pos) {
		if (pos > size()) {
			return '\0';
		}
		return data_[pos];
	}
	// 为了支持 std::cout << 输出
	friend std::ostream &operator<<(std::ostream &output, String &rhs) {
		output << rhs.c_str();
		return output;
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

private:
	char *data_;
};

int32_t main(int32_t, char**) {
	String str1("Hello");
	String str2(str1);
	std::cout << str2 << std::endl;
	std::cout << str2.size() << std::endl;
	std::cout << str2[4] << std::endl;
	exit(EXIT_SUCCESS);
}
