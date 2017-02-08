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

void mystrcpy(char *dest, const char *src, int len) {
	while ((*dest = *src) != '\0' && len > 0) {
		++dest;
		++src;
		--len;
	}
	*dest = '\0';
}

class String {
public:
	String(void) : data_(new char[1]) {
		std::cout << "called 1" << std::endl;
		data_[0] = '\0';
	}
	String(const char *str) : data_(new char[mystrlen(str) + 1]) {
		mystrcpy(data_, str, mystrlen(str));
	}
	String(const String &rhs) : data_(new char[rhs.size() + 1]) {
		mystrcpy(data_, rhs.c_str(), rhs.size());
	}
	String(String &&rhs) : data_(rhs.data_) {
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
		
	friend std::ostream &operator<<(std::ostream &output, String &rhs) {
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

template<typename T>
class PrintElements {
public:
	void operator()(T &rhs) {
		std::cout << rhs << ", ";
	}
};

typedef std::vector<String> SVec;
int main(int, char**) {
	String str1("Hello world!");
	String str2(str1);
	std::cout << str1 << ", " << str2 << std::endl;
	SVec svec(5, "resize");			// 用元素的默认构造函数构造了5个新的元素, resize(5, val)
	//svec.reserve(5);				// 增加了vector的capacity，但是它的size没有改变, 设置容量（capacity）
	//svec.resize(5);				// resize改变了vector的capacity同时也增加了它的size, 设置大小（size）
	svec.push_back(str1);
	svec.push_back(str2);
	std::cout << "size: " << svec.size() << std::endl;
	std::for_each(svec.begin(), svec.end(), PrintElements<String>());
	std::cout << std::endl;
	exit(EXIT_SUCCESS);
}

