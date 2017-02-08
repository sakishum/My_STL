#include <stdio.h>
#include <stdlib.h>
#include <iostream>

template<typename T>
class allocator {
public:
	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

	pointer allocate(size_type n) {
		return ::allocatoe((difference_type)n, (pointer)0);
	}

	void deallocate(pointer p) {
		::deallocate(p);
	}

	pointer address(reference x) {
		return (pointer)&x;
	}
	const_pointer const_address(const_reference x) {
		return (const_pointer)&x;
	}
	size_type max_size(void) const {
		return max(size_type(1), size_type(UINT_MAX/sizeof(T)));
	}
};

int main(int, char**) {
	exit(EXIT_SUCCESS);
}

