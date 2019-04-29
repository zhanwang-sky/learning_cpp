#include <iostream>
#include "str_blob.h"

using namespace std;

StrBlob b1 = { "hello", "world" };

int main(void) {
    StrBlob b2;

    b2 = b1;
    cout << b2.size() << endl;

    b2.push_back("!!!");
    cout << b1.size() << endl;

    return 0;
}
