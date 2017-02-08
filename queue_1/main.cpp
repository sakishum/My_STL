/**
 * @file main.cpp
 * @Synopsis  Example for STL queue(fist in fist out, FIFO) in CPP.
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2013-10-25
 */

#include <cstdlib>
#include <iostream>
#include <queue>

int main(void) {
	std::queue<std::string> waiting_line;
	while (waiting_line.size() < 5) {
		std::cout << "Wellcome to the line, please enter your name: ";
		std::string str;
		getline(std::cin, str);
		waiting_line.push(str);
	}
	while (!waiting_line.empty()) {
		std::cout << "Now serving: " << waiting_line.front() << std::endl;
		waiting_line.pop();
	}
	return EXIT_SUCCESS;
}

//Wellcome to the line, please enter your name: sakishum1
//Wellcome to the line, please enter your name: sakishum2
//Wellcome to the line, please enter your name: sakishum3
//Wellcome to the line, please enter your name: sakishum4
//Wellcome to the line, please enter your name: sakishum5
//Now serving: sakishum1
//Now serving: sakishum2
//Now serving: sakishum3
//Now serving: sakishum4
//Now serving: sakishum5
