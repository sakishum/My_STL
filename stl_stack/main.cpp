#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <stack>

auto main(int32_t, char**) -> int32_t {
	std::stack<int32_t> sta;
	sta.push(1);
	sta.push(2);
	sta.push(3);
	sta.push(4);

	while (!sta.empty()) {
		printf("%d, ", sta.top());
		sta.pop();
	}
	exit(EXIT_SUCCESS);
}
