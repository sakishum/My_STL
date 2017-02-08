#include <cstdio>
#include <cstdlib>
#include <deque>
#include <cstdint>
#include <iostream>

using namespace std;

int main(void) {
	deque<int> d1 {1,2,3,4,5},d2,d3;
    d1.swap(d2);
    deque<int>::iterator it;
    cout << "d1 swap after:" ;
	if (d1.empty()) {
		cout << "d1 is empty.";
	}
    for(it=d1.begin();it!=d1.end();it++){
        cout << *it << " ";
    }
    cout << endl;
    cout << "d2 swap after:" ;
    for(it=d2.begin();it!=d2.end();it++){
        cout << *it << " ";
    }
    cout << endl;
    
    swap(d3,d2);
    cout << "d3 swap after:" ;
    for(it=d3.begin();it!=d3.end();it++){
        cout << *it << " ";
    }
    cout << endl;
    cout << "d2 swap after:" ;
    for(it=d2.begin();it!=d2.end();it++){
        cout << *it << " ";
    }
    cout << endl;
	deque<int>().swap(d3);
    cout << "d3 swap after:" ;
    for(it=d3.begin();it!=d3.end();it++){
        cout << *it << " ";
    }
    cout << endl;
	return EXIT_SUCCESS;
}
