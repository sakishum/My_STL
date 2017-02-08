/**
 * @file main.cpp
 * @Synopsis  優先順位付きでoperator<()を定義するにはどうすればいいでしょうか.
 * @url http://faithandbrave.hateblo.jp/entry/20121210/1355126432
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-04-20
 */

#include <cstdlib>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>

struct File {
	std::string type;
	std::string name;

	File(const std::string &type, const std::string &name) 
	: type(type), name(name) { }
};

bool operator<(const File &a, const File &b) {
	return std::tie(a.type, a.name) < std::tie(b.type, b.name);
}

int main(void) {
	std::vector<File> files = {
		{"text", "b.txt"},
		{"application", "b.txt"},
		{"application", "a.txt"},
		{"text", "a.txt"},
	};

	std::sort(files.begin(), files.end());

	for (const File &file : files) {
		std::cout << "Type: " << file.type << ", Name: " << file.name << std::endl;
	}
	return EXIT_SUCCESS;
}
