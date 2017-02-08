#include <stdio.h>
#include <stdlib.h>
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

void mystrcpy(char *dest, const char *src) {
	while ((*dest = *src) != '\0') {
		++dest;
		++src;
	}
	*dest = '\0';
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
		rhs.data_ = NULL;
	}
	virtual ~String(void) {
		delete [] data_;
	}
	String &operator=(String str) {
		swap(str);
		return *this;
	}
	String &operator=(String &&rhs) {
		swap(rhs);
		return *this;
	}
	char operator[](size_t pos) {
		return data_[pos];
	}
	friend std::ostream &operator<<(std::ostream &output, String &str) {
		output << str.c_str();
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

template<typename T>
class PrintElem {
public:
	void operator()(String &rhs) {
		std::cout << rhs << ", ";
	}
};

int main(int, char**) {
	String str1("Hello");
	String str2(str1);
	std::vector<String> svec;
	svec.push_back(str1);
	svec.push_back(str2);
	svec.emplace_back("world");
	std::for_each(svec.begin(), svec.end(), PrintElem<String>());
	exit(EXIT_SUCCESS);
}
