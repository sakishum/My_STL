/**
 * @file main.cpp
 * @Synopsis  Example for vector::shrink_to_fit() in CPP.
 *	
 *		Requests the container to reduce its capacity to fit its size.
 *		The request is non-binding, and the container implementation is free to optimize otherwise and 
 *		leave the vector with a capacity greater than its size.
 *		This may cause a reallocation, but has no effect on the vector size and cannot alter its elements.
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-02-26
 */

#include <cstdlib>
#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> myvect = {1,2,3,4,5,6,7,8,9,0};
	std::cout << "1. capacity of myvect:" << myvect.capacity() << std::endl;
	myvect.resize(3);
	std::cout << "2. capacity of myvect:" << myvect.capacity() << std::endl;
	myvect.shrink_to_fit();
	std::cout << "3. capacity of myvect:" << myvect.capacity() << std::endl;
	return EXIT_SUCCESS;
}
