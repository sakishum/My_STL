#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>

class String {
public:
	String(void) : data_(new char[1]) {
		assert(data_);
		data_[0] = '\0';
	}

	String(const char *str) : data_(new char[strlen(str) + 1]) {
		strcpy(data_, str);	
	}

	String(const String &rhs) : data_(new char[rhs.size() + 1]) {
		strcpy(data_, rhs.c_str());
	}

	String(String &&rhs) : data_(rhs.data_) {
		rhs.data_ = nullptr;
	}

	~String(void) {
		delete [] data_;
	}

	String &operator()(String rhs) {
		swap(rhs);
		return *this;
	}

	String &operator()(String &&rhs) {
		swap(rhs);
		return *this;
	}

	// 必须 const 不然不能在申请char 数组的时候，在方括号内使用
	size_t size(void) const {
		return strlen(data_);
	}

	const char *c_str(void) const {
		return data_;
	}

	void swap(String &rhs) {
		// 不能使用 rhs.c_str(), 否则不能使用 std::swap
		std::swap(data_, rhs.data_);
	}

private:
	char *data_;
};  // class String

int main(int, char**) {
	String str1;
	String *pstr = new String("aaa");
	delete pstr;
	exit(EXIT_SUCCESS);
}
