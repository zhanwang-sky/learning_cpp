#include <iostream>
#include "hasptr.h"
#include "message.h"
#include "strvec.h"

using namespace std;

#define __FUNC_ENTER() \
do { \
    cout << ">>>" << __FUNCTION__ << "(" << __LINE__ << ") ENTER" << endl; \
} while (false)

#define __FUNC_EXIT() \
do { \
    cout << "<<<" << __FUNCTION__ << "(" << __LINE__ << ") EXIT" << endl; \
} while (false)

void hasptr_demo() {
    cout << "HasPtr hp1" << endl;
    HasPtr hp1;

    cout << "HasPtr hp2(\"balabal\")" << endl;
    HasPtr hp2("fuck!");

    cout << "HasPtr hp3 = hp2" << endl;
    HasPtr hp3 = hp2;

    cout << "hp3 = hp1" << endl;
    hp3 = hp1;
}

void message_demo() {
    __FUNC_ENTER();
    Message m1(__FUNCTION__);
    Message m2(m1);
    __FUNC_EXIT();
}

int main(void) {
    cout << "hello world\n";
    cout << endl;

    hasptr_demo();
    cout << endl;

    message_demo();
    cout << endl;

    return 0;
}
