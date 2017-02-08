#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <iostream>
#include <vector>

int32_t mystrlen(const char *str) {
	if (*str == '\0') {
		return 0;
	} else {
		return mystrlen(str + 1) + 1;
	}
}

int32_t mystrcpy(char *dest, const char *src) {
	int32_t ret = 0;
	
	if (NULL == dest || NULL == src) {
		ret = -1;
		return ret;
	}

	while ((*dest++ = *src++) && *dest != '\0') {
	}

	return ret;
}

int32_t main(int32_t, char**) {
	char str1[30] = "aabbcc";
	const char *str2 = "12345";

	std::cout << mystrlen(str1) << std::endl;
	
	std::cout << mystrcpy(str1, str2) << ", " << str1 << std::endl;

	exit(EXIT_SUCCESS);
}
