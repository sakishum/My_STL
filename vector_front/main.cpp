#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <boost/smart_ptr.hpp>

class Foo {
public:
	int32_t data_;
};

typedef boost::shared_ptr<Foo>  FooPtr;
typedef std::vector<FooPtr> FooVec;

int main(void) {
	FooVec foovec;
	FooPtr foo1 = boost::make_shared<Foo>();
	foo1->data_ = 100;
	foovec.push_back(foo1);
	FooPtr foo2 = boost::make_shared<Foo>();
	foo2->data_ = 200;
	foovec.push_back(foo2);
	
	std::cout << "Vec first element is: " << foovec.front()->data_ << std::endl;
	std::cout << "Vec first element is: " << foovec[0]->data_ << std::endl;
	std::cout << "Vec first element is: " << (*foovec.begin())->data_ << std::endl;
	std::cout << "Vec.size() is: " << foovec.size() << std::endl;

	return EXIT_SUCCESS;
}
