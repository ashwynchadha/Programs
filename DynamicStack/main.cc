#include <iostream>
#include <string>
using namespace std;

#include "tests.h"

string get_status_str(bool status) {
    return status ? "Pass" : "Fail";
}

int main() {
    DynamicStackTest stack_test;


    bool stack_test1_passed = stack_test.test1();
    bool stack_test2_passed = stack_test.test2();
    bool stack_test3_passed = stack_test.test3();

cout << "---Dynamic Stack Tests---" << endl;
    cout << "Test1: " << get_status_str(stack_test1_passed) << endl;
    cout << "Test2: " << get_status_str(stack_test2_passed) << endl;
    cout << "Test3: " << get_status_str(stack_test3_passed) << endl;
    cout << endl;
    

}
