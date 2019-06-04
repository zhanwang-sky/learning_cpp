#include <iostream>
#include "str_blob.h"

using namespace std;

StrBlob b1 = { "hello", "world" };

void echo_str(size_t n) {
    string str;
    allocator<string> a;
    auto const p = a.allocate(n);
    auto q = p;
    while (cin >> str && q != p + n)
        a.construct(q++, str);
    for (q = p; q != p + n; q++) {
        cout << *q << " ";
        a.destroy(q);
    }
    cout << endl;
    a.deallocate(p, n);
}

int main(void) {
    StrBlob b2;

    b2 = b1;
    cout << b2.size() << endl;

    b2.push_back("!!!");
    cout << b1.size() << endl;

    b1.at(2) = "wonderful";

    for (decltype(b2)::size_type i = 0; i < b2.size(); i++) {
        cout << b2.at(i) << " ";
    }
    cout << endl;

    StrBlobPtr pb1 = b1.begin();
    for (int i = 0; i < 3; i++) {
        cout << pb1.deref() << " ";
        pb1.incr();
    }
    cout << endl;

    const StrBlob b3 = b1;
    b3.pop_back();
    cout << b3.size() << endl;

    echo_str(5);

    return 0;
}
