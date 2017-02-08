#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <algorithm>

// non-member function cannot have 'const' qualifier (FixIt)
int32_t mystrlen(const char *str) {
	assert(NULL != str);
	if (*str == '\0') {
		return 0;
	} else {
		return mystrlen(str + 1) + 1;
	}
}

void mystrcpy(char *dst, const char *src) {
	assert(NULL != dst);
	assert(NULL != src);
	while (*src != '\0') {
		*dst++ = *src++;
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
	char operator[](size_t pos) const {
		return data_[pos];
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

	friend std::ostream &operator<<(std::ostream &output, String &str) {
		output << str.c_str();
		return output;
	}

private:
	char *data_;
};

int main(void) {
	String str("Hello");
	String str1(str);
	std::cout << str << std::endl;
	std::cout << str1 << std::endl;
	exit(EXIT_SUCCESS);
}
