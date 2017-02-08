#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

auto main(int, char**) -> int32_t {
	std::map<std::string, int32_t> langs;
	langs["Perl"] = 6;
	langs["C++"] = 2011;
	langs["Java"] = 8;
	langs.insert(std::make_pair("Erlang", 72));

	langs.emplace("lisp", 89);

	auto ret = langs.emplace("Java", 9);
	if (!ret.second) {
		auto pr = *ret.first;
		std::cout << "Exist key: " << pr.first << std::endl;
	}

	// fully agree that [](auto f){ ... } would be very desirable!
	typedef const std::map<std::string, int32_t>::value_type lang_type;
	std::for_each(langs.begin(), langs.end(), 
			[&](const lang_type &iter){ std::cout << iter.first << ", " << iter.second << std::endl; });

	exit(EXIT_SUCCESS);
}
