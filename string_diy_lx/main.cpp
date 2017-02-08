#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <vector>
#include <algorithm>

int mystrlen(const char *str) {
	if (*str == '\0') {
		return 0;
	} else {
		return mystrlen(str + 1) + 1;
	}
}

void mystrcpy(char *dst, const char *src, int len) {
	while (*src != '\0' && len > 0) {
		*dst++ = *src++;
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

	// 加 const ，不然不能在 容器中使用
	String(const String &rhs) : data_(new char[rhs.size() + 1]) {
		mystrcpy(data_, rhs.c_str(), rhs.size());
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

typedef std::vector<String> SVector;
int main(int, char**) {
	String str1("Hello");
	String str2(str1);
	std::cout << str2 << std::endl;
	SVector svec;
	svec.push_back(str1);
	svec.push_back(str2);
	std::for_each(svec.begin(), svec.end(), [](String &str){
				std::cout << str << std::endl;
			});

	exit(EXIT_SUCCESS);
}

