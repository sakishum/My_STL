#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>


int mystrlen(const char *str) {
	if (*str == '\0') {
		return 1;
	} else {
		return mystrlen(str + 1) + 1;
	}
}

void mystrcpy(char *dest, const char *src) {
	while (*src != '\0') {
		*dest = *src;
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
	~String(void) {
		delete [] data_;
	}
	String operator=(String str) {
		swap(str);
		return *this;
	}
	char operator[](int pos) const {
		if (pos <= 0 || pos >= mystrlen(data_)) {
			return '\0';
		}
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
	void swap(String &str) {
		std::swap(data_, str.data_);
	}

private:
	char *data_;
};

template<typename T>
class PrintElm {
public:
	void operator()(T &rhs) {
		std::cout << rhs << ", ";
	}
};

typedef std::vector<String> Svec;
int main(int, char**) {
	Svec svec;
	svec.reserve(5);
	String str1("Hello");
	String str2(str1);
	std::cout << "strlen(str1) = " << mystrlen(str1.c_str()) << std::endl;

	svec.push_back(str2);
	svec.push_back(String("world"));
	std::cout << str1 << std::endl;
	std::for_each(svec.begin(), svec.end(), PrintElm<String>());
	std::cout << std::endl;

	exit(EXIT_SUCCESS);
}
