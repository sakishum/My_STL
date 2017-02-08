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

int mystrcmp(const char *src, const char *sub) {
	int ret = 0;
	while (!(ret = (unsigned int)*src - (unsigned int)*sub) && *sub) {
		++src;
		++sub;
	}

	if (ret < 0) {
		ret = -1;
	} else if (ret > 0) {
		ret = 1;
	}
	return ret;
}

// 构造、析构、拷贝构造、赋值
class String {
public:
	String(void) : data_(new char[1]) {
		data_[0] = '\0';
	}
	String(const char *str) : data_(new char[mystrlen(str) + 1]) {
		mystrcpy(data_, str, mystrlen(str));
	}
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
	bool operator==(const String &rhs) {
		bool ret = false;
		if (0 == mystrcmp(data_, rhs.c_str())) {
			ret = true;;
		}
		return ret;
	}
	char operator[](size_t pos) const {
		if (pos > static_cast<size_t>(mystrlen(data_))) {
			return '\0';
		}
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

template <typename T>
class PrintElems {
public:
	void operator()(const T &rhs) {
		std::cout << rhs << ", ";
	}
};

// 模板特化
template<>
 void PrintElems<String>::operator()(const String &rhs) {
	std::cout << rhs << ",_ "; 
 }

int main(int, char**) {
	String str1("Hello");
	std::cout << str1 << ", size: " << str1.size() << std::endl;
	String str2(str1);
	std::cout << str2 << ", size: " << str2.size() << std::endl;
	if (str1 == str2) {
		std::cout << "Is same." << std::endl;
	}
	std::vector<String> svec;
	svec.reserve(3);
	svec.push_back(str1);
	svec.push_back(str2);
	svec.emplace_back("aabb");
	svec.push_back("good job");
	std::for_each(svec.begin(), svec.end(), PrintElems<String>());
	exit(EXIT_SUCCESS);
}
