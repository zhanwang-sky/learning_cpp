#include <iostream>
#include <utility>
#include "hasptr.h"
#include "message.h"
#include "strvec.h"
#include "string.h"

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

void String_demo() {
    __FUNC_ENTER();

    String s1("hahahah");
    cout << "s1 = " << s1.c_str() << endl;

    do {
        String s2 = "hello world";
        cout << "s1 <=X s2\n";
        s1 = std::move(s2);
    } while (false);

    cout << "s1 = " << s1.c_str() << endl;

    String s3 = "ni hao";
    cout << "s3 <= s3\n";
    s3 = s3;
    cout << "s3 <=X s3\n";
    s3 = std::move(s3);
    cout << "s3 = " << s3.c_str() << endl;

    __FUNC_EXIT();
}

int main(void) {
    cout << "hello world\n";
    cout << endl;

    hasptr_demo();
    cout << endl;

    message_demo();
    cout << endl;

    String_demo();
    cout << endl;

    return 0;
}
