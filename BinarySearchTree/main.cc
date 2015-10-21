#include <iostream>
#include <string>
using namespace std;

#include "tests.h"

string get_status_str(bool status)
{
    return status ? "Pass" : "Fail";
}

int main()
{
    BinarySearchTreeTest btree_test;


    bool btree_test1_passed = btree_test.test1();
    bool btree_test2_passed = btree_test.test2();
    bool btree_test3_passed = btree_test.test3();


    cout << "---Binary Search Tree Tests---" << endl;
    cout << "Test1: " << get_status_str(btree_test1_passed) << endl;
    cout << "Test2: " << get_status_str(btree_test2_passed) << endl;
    cout << "Test3: " << get_status_str(btree_test3_passed) << endl;


}
