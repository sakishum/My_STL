/**
 * @file main.cpp
 * @Synopsis	Example for std::advance, std::distance.
 *		Increments given iterator it by n elements.
 *		it	-	iterator to be advanced
 *		n	-	number of elements it should be advanced
 *		Complexity : Linear.
 *
 *		returns the distance between two iterators.
 *		first	-	iterator pointing to the first element
 *		last	-	iterator pointing to the end of the range
 *		Complexity : Linear.
 *
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-12-22
 */

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

typedef std::vector<int32_t> Ivec;

int main(void) {
	Ivec ivec = {1, 2, 3, 4};
	auto iter = ivec.begin();
	std::advance(iter, 2);

	std::cout << "The data is: " << *iter << std::endl;		// 3
	std::cout << "The distance between begin and end is: " << std::distance(ivec.begin(), ivec.end()) << std::endl;	// 4
	return EXIT_SUCCESS;
}
