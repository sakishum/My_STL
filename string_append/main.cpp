#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <string>

auto main(int32_t, char**) -> int32_t {
	char mesage[10] = "123456789";
	std::string str;
	str.append(mesage, strlen(mesage));
	printf("str=%s, length=%zu\n", str.c_str(), str.size());
	if (str.empty()) {
		printf("empty message.\n");
	}
	exit(EXIT_SUCCESS);
}
