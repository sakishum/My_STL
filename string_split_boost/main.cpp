/**
 * @file main.cpp
 * @Synopsis  Example for split string by Boost::splite.
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-06-24
 */

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <vector>
#include <string>

template<typename T>
struct PrintVec {
public:
	void operator()(const T &elem) {
		std::cout << elem << std::endl;
	}

};

int main(void) {
	//std::string str = "a,b c ,,e,f";
	std::string str = "192.168.1.228:30000";
	std::vector<std::string> tokens;
	std::cout << "Original = \"" << str << "\"" << std::endl;
	std::cout << "Split on \',\' only" << std::endl;
	boost::split(tokens, str, boost::is_any_of(","));
	for_each(tokens.begin(), tokens.end(), PrintVec<std::string>());

	std::vector<std::string>().swap(tokens);
	std::cout << "Splite on \' ,\' " <<std::endl;
	boost::split(tokens, str, boost::is_any_of(" ,"));
	for_each(tokens.begin(), tokens.end(), PrintVec<std::string>());

	std::vector<std::string>().swap(tokens);
	std::cout << "Splite on \' ,\' and elide delimiters" <<std::endl;
	//boost::split(tokens, str, boost::is_any_of(" ,"), boost::token_compress_on);
	boost::split(tokens, str, boost::is_any_of(":"), boost::token_compress_on);
	for_each(tokens.begin(), tokens.end(), PrintVec<std::string>());
	return EXIT_SUCCESS;
}
