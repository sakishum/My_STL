#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>

struct Test {
	int data;
	Test(void) : data(1024) {
		printf("Enter.\n");
	}
};

typedef std::map<int, Test*> Tmap;

int main(int, char**) {
	Tmap tmap;
	Test *ptest = tmap[1];
	std::cout << tmap.size() << std::endl;		// 1
	if (!ptest) {
		printf("Check.\n");
		std::cout << ptest->data << std::endl;
	}

	exit(EXIT_SUCCESS);
}
