#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

#define MAX_LEN 100

int main(void) {
	char str[MAX_LEN] = {0};
	std::string cpy(str);
	std::cout << "Str: " << cpy << std::endl;
	return EXIT_SUCCESS;
}
