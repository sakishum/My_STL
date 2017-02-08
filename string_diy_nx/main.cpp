#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <algorithm>
#include <vector>

int32_t mystrlen(const char *str) {
	if (*str == '\0') {
		return 0;
	} else {
		return mystrlen(str + 1) + 1;
	}
}

void mystrcpy(char *dst, const char *src, int len) {
	while ((*dst = *src) != '\0' && len > 0) {
		++dst;
		++src;
		--len;
	}
	*dst = '\0';
}

class String {
public:
	String(void) : data_(new char[1]) {
		data_[0] = '\0';
	}
	String(const char *str) : data_(new char[mystrlen(str) + 1]) {
		mystrcpy(data_, str, mystrlen(str));
	}
	// 必须使用 const
	//String(String &rhs) : data_(new char[rhs.size() + 1]) {
	String(const String &rhs) : data_(new char[rhs.size() + 1]) {
		mystrcpy(data_, rhs.c_str(), rhs.size());
	}
	String(String &&rhs) : data_(rhs.data_) {
		rhs.data_ = NULL;
	}
	~String(void) {
		delete [] data_;
		data_ = NULL;
	}
	String &operator=(String rhs) {
		swap(rhs);
		return *this;
	}
	String &operator=(String &&rhs) {
		swap(rhs);
		return *this;
	}
	char operator[](size_t pos) const {
		return data_[pos];
	}
	friend std::ostream &operator << (std::ostream &output, String &rhs) {
		output << rhs.c_str();
		return output;
	}

	const char *c_str(void) const {
		return data_;
	}
	int32_t size(void) const {
		return mystrlen(data_);
	}
	// 不能使用 const
	void swap(String &rhs) {
		std::swap(data_, rhs.data_);
	}

private:
	char *data_;
};

void foo(String &str) {
	std::cout << "foo() called, " << str << std::endl;
}

auto main(int, char**) -> int32_t {
	std::vector<String> svec;
	String str1("hello");
	String str2(str1);
	std::cout << str2 << std::endl;
	svec.push_back(str1);
	svec.push_back(str2);
	svec.emplace_back("world");
	foo(svec.at(2));
	std::for_each(svec.begin(), svec.end(), [](std::vector<String>::value_type &str) {
				std::cout << str << ", ";
			});
	std::cout << std::endl;
	exit(EXIT_SUCCESS);
}

