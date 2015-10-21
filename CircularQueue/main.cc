#include <iostream>
#include <string>
using namespace std;

#include "tests.h"

string get_status_str(bool status) {
    return status ? "Pass" : "Fail";
}

int main() {

    CircularQueueTest queue_test;

    bool queue_test1_passed = queue_test.test1();
    bool queue_test2_passed = queue_test.test2();
    bool queue_test3_passed = queue_test.test3();


    cout << "---Circular Queue Tests---" << endl;
    cout << "Test1: " << get_status_str(queue_test1_passed) << endl;
    cout << "Test2: " << get_status_str(queue_test2_passed) << endl;
    cout << "Test3: " << get_status_str(queue_test3_passed) << endl;


}
