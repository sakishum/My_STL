#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>	// sort, max_element, random_shuffle, remove_if, lower_bound
#include <functional>	// greater
#include <iterator>		// begin, end, cbegin, cend, distence

auto main(int, char**) -> int {
	std::array<int, 4> arr{1, 2, 3, 4};

	// initialize a vector from an array
	std::vector<int> numbers(arr.cbegin(), arr.cend());

	// insert more numbers into the vector
	numbers.push_back(5);
	numbers.push_back(6);
	numbers.push_back(7);
	numbers.push_back(8);
	// the vector currently holds {1, 2, 3, 4, 5, 6, 7, 8}
	
	// randomly shuffle the element
	std::random_shuffle(begin(numbers), end(numbers));
	std::for_each(numbers.cbegin(), numbers.cend(), [](const int &num){ std::cout << num << std::endl; });

	// locate the largest element, O(n)
	auto largest = std::max_element(numbers.cbegin(), numbers.cend());

	std::cout << "The largest number is " << *largest << std::endl;
	std::cout << "It is located at index " << std::distance(largest, numbers.cbegin()) << std::endl;

	// sort the elements
	std::sort(begin(numbers), std::end(numbers));

	// find the position of number 5 in the vector
	auto five = std::lower_bound(numbers.cbegin(), numbers.cend(), 5);

	std::cout << "The number 5 is located at index " << std::distance(five, numbers.cend()) << std::endl;

	// erase all the elements greater than 4
	numbers.erase(std::remove_if(std::begin(numbers), std::end(numbers),
				std::bind(std::greater<int>{}, std::placeholders::_1, 4)), std::end(numbers));

	// print all the remaining numbers
	for (const auto &element : numbers) {
		std::cout << element << " ";
	}

	exit(EXIT_SUCCESS);
}

