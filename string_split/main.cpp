#include <cstdio>
#include <cstdlib>
#include <string>		// std::string
#include <sstream>		// std::istringstream
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>		// std::vector

// functor 
struct PrintVec {
public:
	void operator()(const std::string &elem) {
		std::cout << "Elem: " << elem << std::endl;
	}
};

// Best string spliter:
// /Users/sakishum1118/MyBoost/asio_google_log
int main(void) {
	// Can't deal with varying delimiters ans is VERY VERY inefficient. in short DO NOT use this code anywhere.
	std::string sentence = "And I feel fine ...";
	std::istringstream iss (sentence);
	//std::copy(std::istream_iterator<std::string>(iss),
			//std::istream_iterator<std::string>(),
			//std::ostream_iterator<std::string>(std::cout, "\n"));

	std::vector<std::string> tokens;
	std::copy(std::istream_iterator<std::string>(iss),
			std::istream_iterator<std::string>(),
			std::back_inserter(tokens));

	std::cout << "Tokens size: " << tokens.size() << std::endl;
	for_each(tokens.begin(), tokens.end(), PrintVec());
	return EXIT_SUCCESS;
}
