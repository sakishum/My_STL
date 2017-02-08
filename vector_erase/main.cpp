#include<iostream>
#include<vector>
using namespace std;
 
// vector 的erase函数 删除指定位置的元素时， 返回值是一个迭代器，
// 指向删除元素下一个元素。删除第一个300后，itor指向其后的300，
// 然后执行itor++,指向了500.    执行结果：100 300 500
int main(void) {
    vector<int> array;
    array.push_back(100);
    array.push_back(300);
    array.push_back(300);
    array.push_back(500);
    vector<int>::iterator itor;
    for (itor = array.begin(); itor != array.end(); itor++) {
        if (*itor == 300) {
            itor = array.erase(itor);
        }
    }
    for (itor = array.begin(); itor != array.end(); itor++) {
        cout << *itor << " ";
    }
    return 0;
}
