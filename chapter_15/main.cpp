#include <iostream>
#include "quote.h"

using namespace std;

int main() {
    Quote item1("978-7-121-15535-2", 128);
    Bulk_quote item2("978-0201164879", 66.49, 10, 0.1);
    cout << item1.isbn() << endl;

    item1.debug(cout);
    item2.debug(cout);

    print_total(cout, item1, 8);
    print_total(cout, item2, 3);
    print_total(cout, item2, 15);

    return 0;
}
