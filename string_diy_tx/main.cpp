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

char *mystrcpy(char *dest, const char *src) {
	char *p = dest;
	while ((*dest++ = *src++) != '\0') ;
	return p;
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
	friend std::ostream &operator<<(std::ostream &output, String &str) {
		output << str.c_str();
		return output;
	}

	int size(void) const {
		return mystrlen(data_);
	}
	const char *c_str(void) const {
		return data_;
	}
	void swap(String &str) {
		std::swap(data_, str.data_);
	}

private:
	char *data_;
};

template<typename T>
class PrintElem {
public:
	void operator()(T& val) {
		std::cout << val << "\t ";
	}
};

int main(int, char**) {
	char a[] = "AABBCC";
	char b[10];
	std::cout << "Len(a)=" << mystrlen(a) << std::endl;
	std::cout << mystrcpy(b, a) << std::endl;
	String str1("Hello");
	String str2(str1);
	std::cout << "Str2 : " << str2 << std::endl;
	std::vector<String> svec;
	svec.push_back(str1);
	svec.emplace_back("World");
	std::for_each(svec.begin(), svec.end(), PrintElem<String>());
	exit(EXIT_SUCCESS);
}


