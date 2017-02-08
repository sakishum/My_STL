#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <vector>

int mystrlen(const char *str) {
	if (*str == '\0') {
		return 0;
	} else {
		return mystrlen(str + 1) + 1;
	}
}

void mystrncpy(char *dst, const char *src, int len) {
	assert(NULL != dst);
	assert(NULL != src);
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
		mystrncpy(data_, str, mystrlen(str));
	}
	String(const String &rhs) : data_(new char[rhs.size() + 1]) {
		mystrncpy(data_, rhs.c_str(), rhs.size());
	}
	String(String &&rhs) : data_(rhs.data_) {
		rhs.data_ = NULL;
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
	char operator[](size_t pos) {
		return data_[pos];
	}
	friend std::ostream &operator<<(std::ostream &output, const String &rhs) {
		output << rhs.c_str();
		return output;
	}

	int size(void) const {
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

int main(int, char**) {
	String str1("Hello");
	String str2(str1);
	std::cout << "str2: " << str2 << std::endl;
	std::vector<String> svec;
	svec.push_back(str1);
	svec.push_back(str2);
	std::for_each(svec.begin(), svec.end(), [](String &rhs) { std::cout << rhs << ", "; });
	exit(EXIT_SUCCESS);
}
